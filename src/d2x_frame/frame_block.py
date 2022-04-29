import hashlib
from typing import List


class FrameBlock:

    def __init__(self,
                 x_dest: int, y_dest: int,
                 x_copy: int, y_copy: int, block_size: int):
        """
        A block to represent a vector movement for two blocks between
        """
        self.x_dest = x_dest
        self.y_dest = y_dest
        self.x_copy = x_copy
        self.y_copy = y_copy
        self.block_size = block_size

    def reverse(self) -> 'FrameBlock':
        return FrameBlock(x_dest=self.x_copy, y_dest=self.y_copy,
                          x_copy=self.x_dest, y_copy=self.y_dest,
                          block_size=self.block_size)

    def scale(self, scale_factor: int) -> 'FrameBlock':
        return FrameBlock(x_dest=self.x_dest * scale_factor, y_dest=self.y_dest * scale_factor,
                          x_copy=self.x_copy * scale_factor, y_copy=self.y_copy * scale_factor,
                          block_size=self.block_size * scale_factor)

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __hash__(self):
        return int(hashlib.md5(bytes(str(self), 'utf-8')).hexdigest(), 16)

    def __str__(self):
        return f"block_size: {self.block_size} x_dest: {self.x_dest} y_dest {self.y_dest} x_copy: {self.x_copy} y_copy: {self.y_copy}"

    @classmethod
    def make_frame_blocks_static(cls, width: int, height: int, block_size: int) -> List['FrameBlock']:
        list_of_blocks: List[FrameBlock] = []

        for x in range(0, width, block_size):
            for y in range(0, height, block_size):
                list_of_blocks.append(FrameBlock(x, y, x, y, block_size))

        return list_of_blocks
