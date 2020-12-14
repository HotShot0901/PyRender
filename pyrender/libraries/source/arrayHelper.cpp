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
}
