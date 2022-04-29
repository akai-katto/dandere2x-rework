from __future__ import annotations
from typing import List, Tuple

import numpy
import numpy as np


def copy_frame_block_old(frame_n: 'D2xFrame', frame_n_1: 'D2xFrame', block: 'FrameBlock') -> None:
    """
    :param frame_n:
    :param frame_n_1:
    :param block:
    :return:
    """
    __assert_valid(frame_n, frame_n_1, block)
    __copy_from(frame_n_1._frame_array, frame_n._frame_array,
                (block.y_copy, block.x_copy),
                (block.y_dest, block.x_dest),
                (block.y_dest + block.block_size - 1, block.x_dest + block.block_size - 1))


def copy_frame_block(frame_n: 'D2xFrame', frame_n_1: 'D2xFrame', block: 'FrameBlock') -> None:
    """
    :param frame_n:
    :param frame_n_1:
    :param block:
    :return:
    """
    __assert_valid(frame_n, frame_n_1, block)
    __copy_from_new(frame_n_1._frame_array, frame_n._frame_array,
                (block.y_copy, block.x_copy),
                (block.y_dest, block.x_dest),
                block_size=block.block_size)

# for experimentation
def _mean_squared_error(frame_n: 'D2xFrame',
                        frame_n_1: 'D2xFrame',
                        block: 'FrameBlock') -> float:
    """
    Computes mean squared error between two blocks.
    """

    def mse(A, B, A_start, B_start, B_end):
        """
        A_start is the index with respect to A of the upper left corner of the overlap
        B_start is the index with respect to B of the upper left corner of the overlap
        B_end is the index of with respect to B of the lower right corner of the overlap
        """
        try:
            A_start, B_start, B_end = map(np.asarray, [A_start, B_start, B_end])
            shape = B_end - B_start
            B_slices = tuple(map(slice, B_start, B_end + 1))
            A_slices = tuple(map(slice, A_start, A_start + shape + 1))

            return (np.square(A[A_slices] - B[B_slices])).mean(axis=None)

        except ValueError:
            raise ValueError

    __assert_valid(frame_n, frame_n_1, block)
    return mse(frame_n_1._frame_array, frame_n._frame_array,
               (block.y_copy, block.x_copy),
               (block.y_dest, block.x_dest),
               (block.y_dest + block.block_size - 1, block.x_dest + block.block_size - 1))


def __assert_valid(frame: 'D2xFrame', frame_other: 'D2xFrame', block: 'FrameBlock') -> None:
    """
    Provide detailed reasons why a copy_block will not work before it's called. This method should access
    every edge case that could prevent copy_block from successfully working.
    :raises ValueError: Invalid copy block request.
    """

    if block.x_dest + block.block_size - 1 > frame.width or block.y_dest + block.block_size - 1 > frame.height:
        raise ValueError('Invalid Dimensions for Dandere2x Image, See Log. Case 1')

    elif block.x_copy + block.block_size - 1 > frame_other.width or block.y_copy + block.block_size - 1 > frame_other.height:
        raise ValueError('Invalid Dimensions for Dandere2x Image, See Log. Case 2')

    elif block.x_dest < 0 or block.y_dest < 0:
        raise ValueError('Input dimensions invalid for copy block, Case 3')

    elif block.x_copy < 0 or block.y_copy < 0:
        raise ValueError('Input dimensions invalid for copy block, Case 4')

    # # Print Out Degenerate Values
    # print('this_x + block_size - 1 > self.width')
    # print(str(this_x + block_size - 1) + '?>' + str(self.width))
    #
    # print('this_y + block_size - 1 > self.height')
    # print(str(this_y + block_size - 1) + '?>' + str(self.height))


def __copy_from(A, B, A_start, B_start, B_end):
    """
    A_start is the index with respect to A of the upper left corner of the overlap
    B_start is the index with respect to B of the upper left corner of the overlap
    B_end is the index of with respect to B of the lower right corner of the overlap
    """
    try:
        A_start, B_start, B_end = map(np.asarray, [A_start, B_start, B_end])
        shape = B_end - B_start
        B_slices = tuple(map(slice, B_start, B_end + 1))
        A_slices = tuple(map(slice, A_start, A_start + shape + 1))
        B[B_slices] = A[A_slices]

    except ValueError:
        raise ValueError


def __copy_from_new(A: np.ndarray, B: np.ndarray,
                    A_start: Tuple[int, int], B_start: Tuple[int, int],
                    block_size: int):
    """
    A_start is the index with respect to A of the upper left corner of the overlap
    B_start is the index with respect to B of the upper left corner of the overlap
    B_end is the index of with respect to B of the lower right corner of the overlap
    """
    try:
        A_start, B_start = map(np.asarray, [A_start, B_start])
        shape = [block_size, block_size]

        B_slices = tuple(map(slice, B_start, B_start + shape))
        A_slices = tuple(map(slice, A_start, A_start + shape))
        B[B_slices] = A[A_slices]

    except ValueError:
        raise ValueError
