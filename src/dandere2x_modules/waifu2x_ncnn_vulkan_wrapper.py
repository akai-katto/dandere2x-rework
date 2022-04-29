import time
from pathlib import Path

import numpy as np
from PIL import Image
from waifu2x_ncnn_vulkan_python import Waifu2x
from d2x_frame.dandere2x_frame import D2xFrame


class Waifu2xNcnnVulkanWrapper:

	def __init__(self):
		self.waifu2x = Waifu2x(gpuid=0, scale=2, noise=3)

	def upscale_image(self, some_frame: D2xFrame) -> D2xFrame:
		input_image = Image.fromarray(some_frame._frame_array.astype('uint8'), 'RGB')
		upscaled_image = self.waifu2x.process(input_image)

		return D2xFrame.from_ndarray(np.array(upscaled_image))


if __name__ == "__main__":
	some_client = Waifu2xNcnnVulkanWrapper()
	some_client2 = Waifu2xNcnnVulkanWrapper()

	some_d2x = D2xFrame.from_file(Path("/home/tyler/Documents/dandere2x_scratch_folder/output1.png"))
	some_image = some_client.upscale_image(some_d2x)
	some_image.save(Path("/home/tyler/Documents/dandere2x_scratch_folder/waifu2x_test.png"))

	other_d2x = D2xFrame.from_file(Path("/home/tyler/Documents/dandere2x_scratch_folder/output1.png"))
	some_image = some_client2.upscale_image(some_d2x)
	some_image.save(Path("/home/tyler/Documents/dandere2x_scratch_folder/waifu2x_test.png"))