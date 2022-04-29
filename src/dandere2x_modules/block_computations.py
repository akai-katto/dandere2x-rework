from typing import List, Tuple

import numpy as np

from d2x_frame.dandere2x_frame import D2xFrame
from d2x_frame.frame_block import FrameBlock
from d2x_frame.frame_manipulations import __assert_valid


def compute_repeat_blocks(frame_n: D2xFrame,
                          frame_n_1: D2xFrame,
                          block_size: int,
                          quality: int) -> Tuple[List[FrameBlock], List[FrameBlock]]:
    """
    This is probably the most important function in dandere2x, and required the most amount of research for me to do.

    :return A tuple containing legal and legal block matches between two frames.
    """
    # Avoid circular imports
    from d2x_frame.frame_block import FrameBlock

    list_of_blocks = FrameBlock.make_frame_blocks_static(frame_n.width, frame_n.height, block_size)
    frame_n_1_compressed = frame_n_1.compress(compression_level=quality)

    frame_n__to__frame_n_1__subtraction: np.array = frame_n._frame_array - frame_n_1._frame_array
    frame_n_1__to__frame_n_1_compressed__subtraction: np.array = frame_n_1._frame_array - frame_n_1_compressed._frame_array

    legal_blocks: List[FrameBlock] = []
    illegal_blocks: List[FrameBlock] = []
    for block in list_of_blocks:

        frame_n__to__frame_n1_mse = mean_block(frame_n__to__frame_n_1__subtraction, block)
        frame_n1_mse__to__frame_n1_mse_compressed = mean_block(frame_n_1__to__frame_n_1_compressed__subtraction, block)

        if frame_n__to__frame_n1_mse < frame_n1_mse__to__frame_n1_mse_compressed:
            legal_blocks.append(block)
        else:
            illegal_blocks.append(block)

    return legal_blocks, illegal_blocks


def mean_block(frame_n: np.array, block: FrameBlock) -> float:
    """
    Computes mean squared error between two blocks.
    """

    def mse(A, B, A_start, B_start, B_end) -> float:
        """
        A_start is the index with respect to A of the upper left corner of the overlap
        B_start is the index with respect to B of the upper left corner of the overlap
        B_end is the index of with respect to B of the lower right corner of the overlap
        """
        try:
            A_start, B_start, B_end = map(np.asarray, [A_start, B_start, B_end])
            shape = B_end - B_start
            A_slices = tuple(map(slice, A_start, A_start + shape + 1))

            return float(np.mean(A[A_slices] ** 2))

        except ValueError:
            raise ValueError

    # __assert_valid(frame_n, frame_n, block)
    return mse(frame_n, frame_n,
               (block.y_copy, block.x_copy),
               (block.y_dest, block.x_dest),
               (block.y_dest + block.block_size - 1, block.x_dest + block.block_size - 1))
