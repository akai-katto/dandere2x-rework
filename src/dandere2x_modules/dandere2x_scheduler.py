from pathlib import Path

from d2x_frame.dandere2x_frame import D2xFrame
from d2x_frame.frame_block import FrameBlock
from dandere2x_modules.block_computations import compute_repeat_blocks
from dandere2x_modules.residual_image import ResidualImage
from dandere2x_modules.waifu2x_ncnn_vulkan_wrapper import Waifu2xNcnnVulkanWrapper
from video_frame_extractor import VideoFrameExtractor


class Dandere2Request:

    def __init__(self, input_video: Path):
        self.input_video = input_video


class Dandere2xScheduler:

    def __init__(self, request: Dandere2Request):
        self._request = request

        self.__current_frame = 1

    def run(self):
        BLEED = 1
        SCALE = 2
        BLOCK_SIZE = 30

        save_prefix = Path("/home/tyler/Documents/dandere2x_scratch_folder/debug")

        waifu2x_vulkan_client = Waifu2xNcnnVulkanWrapper()
        extractor = VideoFrameExtractor(Path("/home/tyler/Downloads/yn_moving.mkv"), 1920, 1080)

        base_frame = extractor.get_frame()

        base_frame_upscaled = waifu2x_vulkan_client.upscale_image(base_frame)
        base_frame_upscaled.save(save_prefix / f"frame{1}.png")

        for x in range(2, 240):
            print(x)
            base_frame_n_1 = extractor.get_frame()
            saved, residuals = compute_repeat_blocks(frame_n=base_frame, frame_n_1=base_frame_n_1,
                                                     quality=90, block_size=BLOCK_SIZE)

            some_residual = ResidualImage(base_image=base_frame_n_1, residual_blocks=residuals, block_size=BLOCK_SIZE)

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
            # debug_frame.save(save_prefix / f"frame{x}.png")


if __name__ == "__main__":
    scheduler = Dandere2xScheduler(None)
    import time

    start = time.time()

    scheduler.run()

    end = time.time()
    print(end - start)

    # extractor = VideoFrameExtractor(Path("/home/tyler/Downloads/yn_moving.mkv"), 1920, 1080)
    #
    # base_frame = extractor.get_frame()
    # next_frame = extractor.get_frame()
    #
    # next_frame.copy_block(base_frame, FrameBlock(0, 0, 0, 0, 30))
