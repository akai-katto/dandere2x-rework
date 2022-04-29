import io
import logging
from copy import copy
from pathlib import Path
from tempfile import SpooledTemporaryFile, TemporaryFile
from typing import List

import imageio
import numpy
import numpy as np

from PIL import Image
from numpy import shape

from d2x_frame.frame_block import FrameBlock
from d2x_frame.frame_manipulations import copy_frame_block, _mean_squared_error


class D2xFrame:
    """
    A wrapper that wraps dandere2x related functions around the PIL / Numpy library, primarily implementing tools and
    fail safe checks that are much needed for dandere2x development.
    """

    DTYPE = np.uint8

    def __init__(self, width: int, height: int,
                 frame_name: str = None,
                 frame_array: np.ndarray = None):
        """
        Instantiates a blank frame with bounds (height, width).

        @param width: Height of the image
        @param height: Width of the image
        @param frame_name: An optional name paramater to help with debugging.
        """

        self._frame_array: np.array = np.zeros([height, width, 3], dtype=D2xFrame.DTYPE)

        if frame_array is not None:
            numpy.copyto(self._frame_array, frame_array)
            del frame_array  # Read only, we copy it into a new buffer

        self.__image_width: int = width
        self.__image_height: int = height

        if frame_name:
            self.frame_name = frame_name
        else:
            self.frame_name = "no frame_name set"

        self._logger = ""

    @classmethod
    def from_file(cls, file_path: Path):
        """
        Returns a Frame instance loading from a text file on disk.
        @param file_path: Location of the file on disk
        """

        frame_array = imageio.imread(file_path).astype(np.uint8)
        if frame_array.shape[0] == 3:
            # Google-collab for some reason, for some images, has the arrays swapped for how the PIL
            # library needs them to be, so this is a workaround for switching the pixel's orders.
            frame_array = np.stack(frame_array, axis=2)

        height = frame_array.shape[0]
        width = frame_array.shape[1]

        instantiated_frame = D2xFrame(width, height)
        instantiated_frame._frame_array = frame_array

        return instantiated_frame

    @classmethod
    def from_ndarray(cls, frame_array: numpy.ndarray):

        height = frame_array.shape[0]
        width = frame_array.shape[1]

        instantiated_frame = D2xFrame(width, height)
        instantiated_frame._frame_array = frame_array

        return instantiated_frame

    def save(self, output_file: Path):

        pil_image = Image.fromarray(self._frame_array.astype(np.uint8))
        pil_image.save(output_file)

    def compress(self, compression_level=100) -> 'D2xFrame':
        """
        Creates a copy of the frame, but with compression. This is used to compute differences between frames, as
        we need to know the acceptable quality loss, when dictated by jpg.
        """
        temp_file = io.BytesIO()

        pil_image = self.__get_pil_image()
        pil_image.save(temp_file, format="JPEG", quality=compression_level)

        new_stream = io.BytesIO(temp_file.getvalue())
        img = Image.open(new_stream)
        self_copy = copy(self)
        self_copy._frame_array = numpy.array(img)
        return self_copy

    # Frame Manipulation #
    """
    Description:
        So we need to have a series of "optimizations" in order to make numpy frame manipulations efficient. Simply 
        iterating over the numpy array using for-loops is extremely slow for python to do. 
    """

    def copy_block(self, frame_other: 'D2xFrame', block: FrameBlock) -> None:
        """
        Copies a block from another frame into this frame.

        :param frame_other: The frame to copy a block from.
        :param block: The "block". Read FrameBlock for more.
        """
        copy_frame_block(self, frame_other, block)

    def copy_block_remove_bleed(self, residual_frame_with_bleeded_blocks: 'D2xFrame', block: FrameBlock, scale: int,
                                bleed: int) -> None:

        bleed_block = copy(block)
        bleed_block.x_copy = block.x_copy + (bleed * scale)
        bleed_block.y_copy = block.y_copy + (bleed * scale)

        copy_frame_block(self, residual_frame_with_bleeded_blocks, bleed_block)

    def copy_block_from_bleed(self, frame_other_bleed: 'D2xBleedFrame', block: FrameBlock, bleed: int) -> FrameBlock:

        bleed_block = copy(block)
        bleed_block.x_copy = block.x_copy + frame_other_bleed.BLEED
        bleed_block.y_copy = block.y_copy + frame_other_bleed.BLEED
        bleed_block.block_size = block.block_size + (2 * bleed)

        self.copy_block(frame_other_bleed, bleed_block)
        return bleed_block

    def mse_block(self, frame_other: 'D2xFrame', block: FrameBlock) -> float:
        """
        Computes mean squared error between this frame and another.

        :param frame_other: The frame to copy a block from.
        :param block: The "block". Read FrameBlock for more.
        """
        return _mean_squared_error(self, frame_other, block)

    # Getters #
    @property
    def width(self) -> int:
        return self.__image_width

    @property
    def height(self) -> int:
        return self.__image_height

    @property
    def np_shape(self) -> List[int]:
        # Note that its height,width - not of my conventional being width, height
        return [self.height, self.width]

    # Image utilities
    def __get_pil_image(self) -> Image:
        return Image.fromarray(self._frame_array.astype(D2xFrame.DTYPE))


class D2xBleedFrame(D2xFrame):
    """
    For residuals processing, pixels may or may not exist when trying to create an residual image based
    off the residual blocks, because of padding. This function will make a larger image, and place the same image
    within the larger image, effectively creating a black bleed around the image itself.

    For example, pretend the series of 1's is a static image

    111
    111
    111

    And we need to get the top left most block, with image padding of one pixel. However, no pixels exist. So we
    create a bleeded image,

    00000
    01110
    01110
    01110
    00000

    Then we can create a residual image of the top left pixel with a padding of one pixel, which would yield

    000
    011
    011
    """

    BLEED = 5

    def __init__(self, input_frame: D2xFrame):
        np_shape = input_frame.np_shape
        x = np_shape[0] + self.BLEED + self.BLEED
        y = np_shape[1] + self.BLEED + self.BLEED

        bleed_image = np.zeros([x, y, 3], dtype=np.uint8)

        self.__copy_from(input_frame._frame_array, bleed_image,
                         (0, 0), (self.BLEED, self.BLEED),
                         (np_shape[0] + self.BLEED - 1, np_shape[1] + self.BLEED - 1))

        super().__init__(width=y, height=x,
                         frame_array=bleed_image,
                         frame_name=input_frame.frame_name + "bleed")

    """
    I don't like to use this raw method, as it's dangerous and cumbersome, hoping to keep it's cognative load
    isolated to this class only.
    https://stackoverflow.com/questions/52702809/copy-array-into-part-of-another-array-in-numpy"""

    @staticmethod
    def __copy_from(A, B, A_start, B_start, B_end):
        """
        A_start is the index with respect to A of the upper left corner of the overlap
        B_start is the index with respect to B of the upper left corner of the overlap
        B_end is the index of with respect to B of the lower right corner of the overlap
        """
        A_start, B_start, B_end = map(np.asarray, [A_start, B_start, B_end])
        shape = B_end - B_start
        B_slices = tuple(map(slice, B_start, B_end + 1))
        A_slices = tuple(map(slice, A_start, A_start + shape + 1))
        B[B_slices] = A[A_slices]
