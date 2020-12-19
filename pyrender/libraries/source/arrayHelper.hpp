#include <cmath>
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

void circleInArray_cpp(int* arr, int* color, int posX, int posY, int r, int width, int height) {
    for (int y = -r; y < r; y++) {
        for (int x = -r; x < r; x++) {
            if ((x*x + y*y) < (r*r)) {
                if ((posX + x) >= 0 && (posY + y) >= 0 && (posY + y) < height && (posX + x) < width) {
                    arr[3*(posY + y)*width + 3*(posX + x) + 0] = color[2];
                    arr[3*(posY + y)*width + 3*(posX + x) + 1] = color[1];
                    arr[3*(posY + y)*width + 3*(posX + x) + 2] = color[0];
                }
            }
        }
    }
}

void lineInArray_cpp(int* arr, int* color, int startX, int startY, int endX, int endY, int thickness, int width, int height) {
    circleInArray_cpp(arr, color, startX, startY, thickness/2, width, height);

    int x = (startX + endX) / 2;
    int y = (startY + endY) / 2;

    int megStartSqr = startX*startX + startY*startY;
    int megMidSqr = x*x + y*y;
    int thicknessSqr = (thickness)*(thickness);

    if ((megMidSqr - megStartSqr) > thicknessSqr) {
        lineInArray_cpp(arr, color, startX, startY, x, y, thickness, width, height);
        lineInArray_cpp(arr, color, x, y, endX, endY, thickness, width, height);
    }
}
