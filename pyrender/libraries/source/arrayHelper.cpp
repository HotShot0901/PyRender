#include <iostream>

void clearArray_cpp(int* arr, int* color, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // RGB to BGR
            arr[3*y*width + 3*x + 0] = color[2];
            arr[3*y*width + 3*x + 1] = color[1];
            arr[3*y*width + 3*x + 2] = color[0];
        }
    }
}

void squareInArray_cpp(int* arr, int* color, int posX, int posY, int w, int l, int width, int height) {
    for (int y = 0; y < l; y++) {
        for (int x = 0; x < w; x++) {
            if ((posX + x) >= 0 && (posY + y) >= 0 && (posY + y) < height && (posX + x) < width) {
                arr[3*(posY + y)*width + 3*(posX + x) + 0] = color[2];
                arr[3*(posY + y)*width + 3*(posX + x) + 1] = color[1];
                arr[3*(posY + y)*width + 3*(posX + x) + 2] = color[0];
            }
        }
    }
}

extern "C" {
    __declspec(dllexport) clearArray(int* arr, int* color, int width, int height) { 
        clearArray_cpp(arr, color, width, height); 
    }

    __declspec(dllexport) squareInArray(int* arr, int* color, int posX, int posY, int l, int w, int width, int height) {
        squareInArray_cpp(arr, color, posX, posY, l, w, width, height);
    }
}
