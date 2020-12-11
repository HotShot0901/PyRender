from pyrender import *

renderer = PyRender((640, 360), bgColor=Color(0, 0, 0))

for i in range(100):
    renderer.drawRect(Vector2(0, 0), Vector2(100, 100), Color(255, 255, 255), DrawMode.Center)
    renderer.nextFrame()

renderer.render("F:\\Python\\Normal\\PyRender")
