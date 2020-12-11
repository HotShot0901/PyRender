import cv2
import os
import numpy as np
from ctypes import cdll, c_int, c_float
from .vectors import *

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
        array = np.array([self.r, self.g, self.b], dtype=int)
        return array

    def __str__(self):
        s = "R: {0:<5} G: {1:<5} B: {2:<5}".format(self.r, self.g, self.b)
        return s

class Shapes:
    Rectangle = 0

class DrawMode:
    Top = 0
    Center = 1
    Bottom = 2

class PyRender:
    # Variables
    dimension = None
    fps = None

    frames = None
    currFrame = None
    lib = None

    bgColor = None

    # Methods
    def __init__(self, dimension, bgColor: Color=Color(0, 0, 0), fps: int=30):
        self.dimension = dimension
        self.fps = fps

        self.bgColor = bgColor

        self.lib = cdll.LoadLibrary(os.path.abspath("./pyrender/libraries/bin/arrayHelper.dll"))

        self.lib.clearArray.argtypes = [
            np.ctypeslib.ndpointer(dtype=int, ndim=1, shape=(dimension[0] * dimension[1] * 3,)),
            np.ctypeslib.ndpointer(dtype=int, ndim=1, shape=(3,)),
            c_int,
            c_int
        ]

        self.lib.squareInArray.argtypes = [
            np.ctypeslib.ndpointer(dtype=int, ndim=1, shape=(dimension[0] * dimension[1] * 3,)),
            np.ctypeslib.ndpointer(dtype=int, ndim=1, shape=(3,)),
            c_int,
            c_int,
            c_int,
            c_int,
            c_int,
            c_int
        ]

        self.frames = []
        self.currFrame = np.zeros((dimension[0] * dimension[1] * 3,), dtype=int)

        self.setBackground(bgColor.asArray())

    def drawRect(self, pos, dimension, color, drawMode):
        center = Vector2(0, 0)

        if drawMode == DrawMode.Top:
            center = pos
        elif drawMode == DrawMode.Center:
            center = pos - Vector2(dimension.x / 2, dimension.y / 2)
        elif drawMode == DrawMode.Bottom:
            center = pos - Vector2(dimension.x, dimension.y)

        
        self.lib.squareInArray(self.currFrame, color.asArray(), int(center.x), int(center.y), int(dimension.x), int(dimension.y), int(self.dimension[0]), self.dimension[1])

    def setBackground(self, color):
        self.lib.clearArray(self.currFrame, color, self.dimension[0], self.dimension[1])

    def nextFrame(self, delCurr=False):
        self.frames.append(self.currFrame.reshape((self.dimension[1], self.dimension[0], 3)))

        if delCurr:
            self.currFrame = np.zeros((self.dimension[0] * self.dimension[1] * 3,), dtype=int)
            self.setBackground(self.bgColor.asArray())

    def render(self, renderPath: str, output: str="video"):
        try:
            os.makedirs(renderPath + "\\frames")
        except:
            os.system("del {0}\\frames".format(renderPath))

        renderPath = renderPath + "\\frames"
        for i in range(len(self.frames)):
            cv2.imwrite("{0}\\frame{1:>010d}.png".format(renderPath, i+1), self.frames[i])

        videoWriter = cv2.VideoWriter(
            renderPath + "\\" + output + ".mp4",
            cv2.VideoWriter.fourcc(*'mp4v'),
            self.fps,
            self.dimension
        )

        for frame in os.listdir("{0}".format(renderPath)):
            frame = cv2.imread("{0}\\{1}".format(renderPath, frame))
            videoWriter.write(frame)

        videoWriter.release()
