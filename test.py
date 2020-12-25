from pyrender import *

renderer = PyRender((640, 360), bgColor=Color(0, 0, 0))

for _ in range(80):
    renderer.drawTriangle(Vector2(50, 50), Vector2(200+_*3, 175), Vector2(110, 240), Color(255, 255, 255))
    renderer.nextFrame(delCurr=True)


for _ in range(40):
    renderer.drawTriangle(Vector2(50, 50), Vector2(440, 170), Vector2(110, 240-_*3), Color(255, 255, 255))
    renderer.nextFrame(delCurr=True)

for _ in range(50):
    renderer.drawTriangle(Vector2(50, 50), Vector2(440, 170), Vector2(110, 120+_*3), Color(255, 255, 255))
    renderer.nextFrame(delCurr=True)

for _ in range(80):
    renderer.drawTriangle(Vector2(50+_*3, 50), Vector2(440, 170), Vector2(110, 270), Color(255, 255, 255))
    renderer.nextFrame(delCurr=True)

renderer.drawTriangle(Vector2(290, 50), Vector2(440, 170), Vector2(110, 270), Color(255, 255, 255))

for _ in range(120):
    renderer.nextFrame()

renderer.render("F:\\Python\\Normal\\PyRender")
