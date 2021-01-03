from pyrender import *

renderer = PyRender((640, 360))

renderer.translate(320, 180)

for _ in range(360):
    # renderer.rotate(math.radians(0))
    # renderer.drawRect(Vector2(100, 0), Vector2(100, 100), Colors.White, DrawMode.Center)

    renderer.rotate(math.radians(_))
    # renderer.drawLine(Vector2(0, 0), Vector2(100, 0), 2, Colors.White)
    renderer.drawRect(Vector2(100, 0), Vector2(100, 100), Colors.White, DrawMode.Center)

    renderer.nextFrame(delCurr=True)

renderer.render("F:\\Python\\Normal\\PyRender")
