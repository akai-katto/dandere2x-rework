import math
import time
from math import sqrt
from multiprocessing import Pool

from pathlib import Path
from typing import List

from d2x_frame.dandere2x_frame import D2xFrame

from dandere2x_modules.residual_image import ResidualImage
from d2x_frame.frame_block import FrameBlock
from dandere2x_modules.block_computations import compute_repeat_blocks


# def some_function(some_n: int):
#     block_size = 15
#     repeat_blocks, residuals = compute_repeat_blocks(frame_n=frame1, frame_n_1=frame2,
#                                                      block_size=block_size, quality=60)


if __name__ == "__main__":

    look_behind = 20
    block_size = 30

    sum_of_all_hashes = set()

    for n in range(look_behind + 1 + 100, 100 + 100):

        base_frame = D2xFrame.from_file(Path(f"/home/tyler/Downloads/yn_moving/output/output{n}.png"))
        new_frame = D2xFrame(base_frame.width, base_frame.height)

        for x in range(n-look_behind, n):
            frame_x = D2xFrame.from_file(Path(f"/home/tyler/Downloads/yn_moving/output/output{x}.png"))
            repeat_blocks, residuals = compute_repeat_blocks(frame_n=frame_x, frame_n_1=base_frame,
                                                             block_size=block_size, quality=25)

            for block in repeat_blocks:
                sum_of_all_hashes.add(block)
                new_frame.copy_block(frame_x, block)

        new_frame.save(Path(f"/home/tyler/Downloads/yn_moving/lower_quality/frame{n}.png"))
