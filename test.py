from pyrender import *

renderer = PyRender((640, 360), bgColor=Color(0, 0, 0))

# renderer.drawLine(Vector2(100, 100), Vector2(200, 200), 4, Color(255, 255, 255))

for _ in range(100):
    renderer.drawLine(Vector2(320, 180), Vector2(320, 180 + _), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(320, 180 - _), 2, Color(255, 255, 255))

    renderer.nextFrame(delCurr=True)
    
for _ in range(100):
    renderer.drawLine(Vector2(320, 180), Vector2(320, 280 ), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(320, 80), 2, Color(255, 255, 255))

    renderer.drawLine(Vector2(320, 180), Vector2(320 + _, 180 - _), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(320 - _, 180 + _), 2, Color(255, 255, 255))

    renderer.nextFrame(delCurr=True)
    
for _ in range(100):
    renderer.drawLine(Vector2(320, 180), Vector2(320, 280 ), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(320, 80), 2, Color(255, 255, 255))

    renderer.drawLine(Vector2(320, 180), Vector2(420, 80), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(220, 280), 2, Color(255, 255, 255))

    renderer.drawLine(Vector2(320, 180), Vector2(320 + _, 180), 2, Color(255, 255, 255))
    renderer.drawLine(Vector2(320, 180), Vector2(320 - _, 180), 2, Color(255, 255, 255))

    renderer.nextFrame(delCurr=True)

renderer.render("F:\\Python\\Normal\\PyRender")
