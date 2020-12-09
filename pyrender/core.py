import cv2
import os
import numpy as np
from vectors import *

class Color:
    r = 0
    g = 0
    b = 0

    def __init__(self, r: int=0, g: int=0, b: int=0):
        if r > 255:
            self.r = 255
        elif r < 0:
            self.r = 0
        else:
            self.r = r
            
        if g > 255:
            self.g = 255
        elif g < 0:
            self.g = 0
        else:
            self.g = g
            
        if b > 255:
            self.b = 255
        elif b < 0:
            self.b = 0
        else:
            self.b = b

    def asArray(self):
        array = np.array([self.r, self.g, self.b], dtype=np.uint8)
        return array

    def __str__(self):
        s = "R: {0:<5} G: {1:<5} B: {2:<5}".format(self.r, self.g, self.b)
        return s

class PyRender:
    # Variables
    dimension = None
    fps = None

    # Methods
    def __init__(self, dimension, fps=30):
        self.dimension = dimension
        self.fps = fps
