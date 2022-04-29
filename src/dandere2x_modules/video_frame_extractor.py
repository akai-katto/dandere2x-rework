from copy import copy

import numpy as np
import subprocess
from pathlib import Path
from d2x_frame.dandere2x_frame import D2xFrame


class VideoFrameExtractor:
    FFMPEG_BINARY = "ffmpeg"

    def __init__(self, input_video: Path, width: int, height: int):
        self.__count: int = 0
        self._width: int = width
        self._height: int = height
        self._dtype = np.uint8

        self.ffmpeg = subprocess.Popen([
            self.FFMPEG_BINARY, "-vsync", "1", "-loglevel", "panic",
            "-i", str(input_video), "-c:v", "rawvideo", "-f", "rawvideo",
            "-pix_fmt", "rgb24", "-an", "-"
        ], stdout=subprocess.PIPE)

    @property
    def current_frame(self) -> int:
        return self.__count

    def get_frame(self) -> D2xFrame:
        """Pipes the raw frames to stdout, converts the bytes to NumPy arrays of RGB data.
        This is a generator so usage is (for Frame in self._GetRawFrames(Video))"""

        raw = self.ffmpeg.stdout.read(self._width * self._height * 3)
        if not raw:
            raise IndexError

        raw = copy(raw)

        self.__count += 1
        return D2xFrame(width=self._width,
                        height=self._height,
                        frame_name=f"frame{self.__count}",
                        frame_array=np.frombuffer(raw, dtype=self._dtype).reshape((self._height, self._width, -1)))


if __name__ == "__main__":

    extractor = VideoFrameExtractor(Path("/home/tyler/Downloads/yn_moving.mkv"), 1920, 1080)
    image_array = []
    for x in range(250):
        some_frame = extractor.get_frame()
        image_array.append(some_frame)
        # some_frame.save(Path(f"/home/tyler/Downloads/end/extracted/output{x}.png"))
