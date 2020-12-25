from pyrender import *

renderer = PyRender((640*3, 360*3), bgColor=Color(0, 0, 0))

renderer.drawTriangle(Vector2(100, 100), Vector2(500, 475), Vector2(110, 680), Color(255, 255, 255))

for _ in range(120):
    renderer.nextFrame()

renderer.render("F:\\Python\\Normal\\PyRender")
