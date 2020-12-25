#include "arrayHelper.hpp"

extern "C" {
    __declspec(dllexport) clearArray(int* arr, int* color, int width, int height) { 
        clearArray_cpp(arr, color, width, height); 
    }

    __declspec(dllexport) squareInArray(int* arr, int* color, int posX, int posY, int l, int w, int width, int height) {
        squareInArray_cpp(arr, color, posX, posY, l, w, width, height);
    }

    __declspec(dllexport) circleInArray(int* arr, int* color, int posX, int posY, int r, int width, int height) {
        circleInArray_cpp(arr, color, posX, posY, r, width, height);
    }

    __declspec(dllexport) lineInArray(int* arr, int* color, int startX, int startY, int endX, int endY, int thickness, int width, int height) {
        lineInArray_cpp(arr, color, startX, startY, endX, endY, thickness, width, height);
    }

    __declspec(dllexport) triangleInArray(int* arr, int* color, int x1, int y1, int x2, int y2, int x3, int y3, int width, int height) {
        triangleInArray_cpp(arr, color, x1, y1, x2, y2, x3, y3, width, height);
    }
}
