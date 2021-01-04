#include "2d_drawCalls.hpp"

struct Vector3 {
    int x, y, z;

    Vector3() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};
