from math import sqrt, ceil
from pathlib import Path
from pprint import pprint
from typing import List, Final
from copy import copy

from dandere2x_modules.block_computations import compute_repeat_blocks
from d2x_frame.dandere2x_frame import D2xFrame, D2xBleedFrame
from d2x_frame.frame_block import FrameBlock
from dandere2x_modules.waifu2x_ncnn_vulkan_wrapper import Waifu2xNcnnVulkanWrapper


class ResidualImage:
    __BLEED = 1

    def __init__(self,
                 base_image: D2xFrame,
                 residual_blocks: List[FrameBlock],
                 block_size: int):
        assert residual_blocks is not None

        self.block_size: Final = block_size

        self._base_image: D2xFrame = base_image
        self._residual_blocks: List[FrameBlock] = residual_blocks

        # Assigned during "process"
        self._completed_residual: D2xFrame = None
        self._residual_reversal: List[FrameBlock] = None

    @property
    def completed_residual_frame(self) -> D2xFrame:
        if self._completed_residual is None:
            raise AttributeError("Frame has not been produced.")

        return self._completed_residual

    @property
    def residual_reversal_blocks(self) -> List[FrameBlock]:
        if self._residual_reversal is None:
            raise AttributeError("Frame has not been produced.")

        return self._residual_reversal

    def process(self) -> None:
        bleed_image: D2xBleedFrame = D2xBleedFrame(self._base_image)

        # This will find the value for 'n', the smallest dimensions of NxN ratio that can fit all the blocks into it,
        # in unit of "blocks".
        n_blocks = ceil(sqrt(len(self._residual_blocks) + 1))

        # When accounting for bleed, the output image with be this big in pixels.
        pixels_for_n_blocks = n_blocks * (self.block_size + (2 * ResidualImage.__BLEED))
        residual_image = D2xFrame(width=pixels_for_n_blocks, height=pixels_for_n_blocks)

        bleed_block_size = self.block_size + (2 * ResidualImage.__BLEED)
        residual_copy = copy(self._residual_blocks)

        residual_reversal: List[FrameBlock] = []

        for x in range(0, n_blocks * bleed_block_size, bleed_block_size):
            for y in range(0, n_blocks * bleed_block_size, bleed_block_size):

                # While the image may still have open space, we might be out of residuals.
                if not residual_copy:
                    break

                iter_block: FrameBlock = residual_copy.pop(0)
                iter_block.x_dest = x
                iter_block.y_dest = y

                residual_image.copy_block_from_bleed(frame_other_bleed=bleed_image,
                                                     block=iter_block,
                                                     bleed=self.__BLEED)

                residual_reversal.append(iter_block.reverse())

        self._completed_residual = residual_image
        self._residual_reversal = residual_reversal


if __name__ == "__main__":
    BLEED = 1
    SCALE = 2
    BLOCK_SIZE = 30

    save_prefix = Path("/home/tyler/Documents/dandere2x_scratch_folder/output")

    waifu2x_vulkan_client = Waifu2xNcnnVulkanWrapper()

    base_frame = D2xFrame.from_file(Path(f"/home/tyler/Downloads/yn_moving/output/output{1}.png"))
    base_frame_upscaled = waifu2x_vulkan_client.upscale_image(base_frame)
    base_frame_upscaled.save(save_prefix / f"frame{1}.png")

    for x in range(2, 10):
        base_frame_n_1 = D2xFrame.from_file(Path(f"/home/tyler/Downloads/yn_moving/output/output{x}.png"))
        saved, residuals = compute_repeat_blocks(base_frame, base_frame_n_1, quality=90, block_size=BLOCK_SIZE)

        some_residual = ResidualImage(base_image=base_frame_n_1,
                                      residual_blocks=residuals,
                                      block_size=BLOCK_SIZE)

        some_residual.process()
        completed_residual_frame = some_residual.completed_residual_frame
        residual_reversal_blocks = some_residual.residual_reversal_blocks

        upscaled_residual_image = waifu2x_vulkan_client.upscale_image(completed_residual_frame)

        for block in residual_reversal_blocks:
            base_frame_n_1.copy_block(frame_other=completed_residual_frame, block=block)

        for block in residual_reversal_blocks:
            scaled_block = block.scale(SCALE)
            base_frame_upscaled.copy_block_remove_bleed(residual_frame_with_bleeded_blocks=upscaled_residual_image,
                                                        block=scaled_block, scale=SCALE, bleed=BLEED)

        base_frame_upscaled.save(save_prefix / f"frame{x}.png")
        base_frame = base_frame_n_1

