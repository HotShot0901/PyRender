#include <cmath>

struct Vector2 {
    int x, y;


    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

void clearArray_cpp(int* arr, int* color, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            arr[3*y*width + 3*x + 0] = color[2];
            arr[3*y*width + 3*x + 1] = color[1];
            arr[3*y*width + 3*x + 2] = color[0];
        }
    }
}

void drawRect_cpp(int* arr, int* color, Vector2 pos, Vector2 dim, float rot, int width, int height) {
    for (int y = -dim.y / 2; y < dim.y / 2; y++) {
        for (int x = -dim.x / 2; x < dim.x / 2; x++) {
            int _x = x;
            int _y = y;

            if (rot != 0) {
                _x = int(cos(rot)*x - sin(rot)*_y);
                _y = int(sin(rot)*x + cos(rot)*_y);
            }

            if ((pos.x + _x) >= 0 && (pos.y + _y) >= 0 && (pos.y + _y) < height && (pos.x + _x) < width) {
                arr[3*(pos.y + _y)*width + 3*(pos.x + _x) + 2] = color[0];
                arr[3*(pos.y + _y)*width + 3*(pos.x + _x) + 0] = color[2];
                arr[3*(pos.y + _y)*width + 3*(pos.x + _x) + 1] = color[1];
            }
        }
    }
}

void drawCircle_cpp(int* arr, int* color, Vector2 pos, int r, int width, int height) {
    for (int y = -r; y < r; y++) {
        for (int x = -r; x < r; x++) {
            if ((x*x + y*y) < (r*r)) {
                if ((pos.y + x) >= 0 && (pos.y + y) >= 0 && (pos.y + y) < height && (pos.x + x) < width) {
                    arr[3*(pos.y + y)*width + 3*(pos.x + x) + 0] = color[2];
                    arr[3*(pos.y + y)*width + 3*(pos.x + x) + 1] = color[1];
                    arr[3*(pos.y + y)*width + 3*(pos.x + x) + 2] = color[0];
                }
            }
        }
    }
}

void drawLine_cpp(int* arr, int* color, Vector2 start, Vector2 end, int thickness, int width, int height) {
    drawCircle_cpp(arr, color, start, thickness/2, width, height);

    int x = (start.x + end.x) / 2;
    int y = (start.y + end.y) / 2;

    int megStartSqr = start.x*start.x + start.y*start.y;
    int megMidSqr = x*x + y*y;
    int thicknessSqr = (thickness)*(thickness);

    if ((megMidSqr - megStartSqr) > thicknessSqr) {
        drawLine_cpp(arr, color, start, Vector2(x, y), thickness, width, height);
        drawLine_cpp(arr, color, Vector2(x, y), end, thickness, width, height);
    }
}

float triangleArea(Vector2 p1, Vector2 p2, Vector2 p3) {
    return abs(( p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) ) / 2);
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

void drawTriangle_cpp(int* arr, int* color, Vector2 p1, Vector2 p2, Vector2 p3, int width, int height) {
    float totalArea = triangleArea(p1, p2, p3);

    int dimX = max(p1.x, p2.x, p3.x) - min(p1.x, p2.x, p3.x) + 1;
    int dimY = max(p1.y, p2.y, p3.y) - min(p1.y, p2.y, p3.y) + 1;

    int posX = min(p1.x, p2.x, p3.x);
    int posY = min(p1.y, p2.y, p3.y);

    for (int x = 0; x < dimX; x++) {
        for (int y = 0; y < dimY; y++) {
            Vector2 v;
            v.x = x + posX;
            v.y = y + posY;

            float area = 0;

            area += triangleArea(v, p2, p3);
            area += triangleArea(v, p1, p3);
            area += triangleArea(v, p1, p2);

            if (totalArea >= area && v.x >= 0 && v.y >= 0 && v.y < height && v.x < width) {
                arr[3*v.y*width + 3*v.x + 0] = color[2];
                arr[3*v.y*width + 3*v.x + 1] = color[1];
                arr[3*v.y*width + 3*v.x + 2] = color[0];
            }
        }
    }
}

void drawQuad_cpp(int *arr, int *color, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, int width, int height) {
    drawTriangle_cpp(arr, color, p1, p2, p4, width, height);
    drawTriangle_cpp(arr, color, p2, p3, p4, width, height);
}
