#include "3d_drawCalls.hpp"

extern "C" {
    __declspec(dllexport) void drawWireCube(int* arr, int* color, Vector3 pos, Vector3 dim, Vector3 rot, float camDist, int width, int height) {
        drawWireCube_cpp(arr, color, pos, dim, rot, camDist, width, height);
    }
}
