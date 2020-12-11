from pyrender import *

renderer = PyRender((640, 360), bgColor=Color(0, 0, 0))

for i in range(50, int(590/4)):
    renderer.drawRect(Vector2(i*4, 50), Vector2(100, 100), Color(255, 255, 255), DrawMode.Center)
    renderer.nextFrame(delCurr=True)

for i in range(50, int(310/4)):
    renderer.drawRect(Vector2(590, i*4), Vector2(100, 100), Color(225, 225, 15), DrawMode.Center)
    renderer.nextFrame(delCurr=True)

for i in range(50, int(590/4)):
    renderer.drawRect(Vector2(640 - i*4, 310), Vector2(100, 100), Color(15, 225, 225), DrawMode.Center)
    renderer.nextFrame(delCurr=True)

for i in range(50, int(310/4)):
    renderer.drawRect(Vector2(50, 360 - i*4), Vector2(100, 100), Color(225, 15, 225), DrawMode.Center)
    renderer.nextFrame(delCurr=True)

renderer.render("F:\\Python\\Normal\\PyRender")
