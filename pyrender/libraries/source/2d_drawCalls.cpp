#include "2d_drawCalls.hpp"

extern "C" {
    __declspec(dllexport) void clearArray(int* arr, int* color, int width, int height) { 
        clearArray_cpp(arr, color, width, height); 
    }

    __declspec(dllexport) void drawRect(int* arr, int* color, Vector2 pos, Vector2 dim, float rot, int width, int height) {
        drawRect_cpp(arr, color, pos, dim, rot, width, height);
    }

    __declspec(dllexport) void drawCircle(int* arr, int* color, Vector2 pos, int r, int width, int height) {
        drawCircle_cpp(arr, color, pos, r, width, height);
    }

    __declspec(dllexport) void drawLine(int* arr, int* color, Vector2 start, Vector2 end, int thickness, int width, int height) {
        drawLine_cpp(arr, color, start, end, thickness, width, height);
    }

    __declspec(dllexport) void drawTriangle(int* arr, int* color, Vector2 p1, Vector2 p2, Vector2 p3, int width, int height) {
        drawTriangle_cpp(arr, color, p1, p2, p3, width, height);
    }

    __declspec(dllexport) void drawQuad(int* arr, int* color, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, int width, int height) {
        drawQuad_cpp(arr, color, p1, p2, p3, p4, width, height);
    }
}
