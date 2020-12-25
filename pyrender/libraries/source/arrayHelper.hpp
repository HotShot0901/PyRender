#include <cmath>

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

float triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs(( x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) ) / 2);
}

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else if (c < a && c < b)
        return c;
}

int max(int a, int b, int c) {
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else if (c > a && c > b)
        return c;
}

void triangleInArray_cpp(int* arr, int* color, int x1, int y1, int x2, int y2, int x3, int y3, int width, int height) {
    float totalArea = triangleArea(x1, y1, x2, y2, x3, y3);

    int dimX = max(x1, x2, x3) - min(x1, x2, x3) + 1;
    int dimY = max(y1, y2, y3) - min(y1, y2, y3) + 1;

    int posX = min(x1, x2, x3);
    int posY = min(y1, y2, y3);

    for (int x = 0; x < dimX; x++) {
        for (int y = 0; y < dimY; y++) {
            int _x = x + posX;
            int _y = y + posY;

            float area = 0;

            area += triangleArea(_x, _y, x2, y2, x3, y3);
            area += triangleArea(_x, _y, x1, y1, x3, y3);
            area += triangleArea(_x, _y, x1, y1, x2, y2);

            if (totalArea >= area && _x >= 0 && _y >= 0 && _y < height && _x < width) {
                arr[3*_y*width + 3*_x + 0] = color[2];
                arr[3*_y*width + 3*_x + 1] = color[1];
                arr[3*_y*width + 3*_x + 2] = color[0];
            }
        }
    }
}
