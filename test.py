from pyrender import *

renderer = PyRender((640, 360), bgColor=Color(0, 0, 0))
renderer.drawQuad(Vector2(100, 100), Vector2(150, 110), Vector2(175, 175), Vector2(90, 150), Color(255, 255, 255))

for _ in range(120):
    renderer.nextFrame()

renderer.render("F:\\Python\\Normal\\PyRender")
