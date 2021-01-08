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

class Vector3_class {
    public:
        int x, y, z;

        Vector3_class() {
            x = 0;
            y = 0;
            z = 0;
        }

        Vector3_class(Vector3* v) {
            x = v->x;
            y = v->y;
            z = v->z;
        }

        Vector3_class operator *(float **matrix) {
            Vector3 *v = new Vector3();

            v->x = matrix[0][0]*x + matrix[0][1]*y + matrix[0][2]*z;
            v->y = matrix[1][0]*x + matrix[1][1]*y + matrix[1][2]*z;
            v->z = matrix[2][0]*x + matrix[2][1]*y + matrix[2][2]*z;

            return Vector3_class(v);
        }
};

float** projection(float dist, int z) {
    float **arr = new float*[3];

    arr[0] = new float[3];

    // First-row
    arr[0][0] = 1 / (dist - z);
    arr[0][1] = 0;
    arr[0][2] = 0;
    
    // Second-row
    arr[1][0] = 0;
    arr[1][1] = 1 / (dist - z);
    arr[1][2] = 0;
    
    // Third-row
    arr[2][0] = 0;
    arr[2][1] = 0;
    arr[2][2] = 0;

    return arr;        
}

void drawWireCube_cpp(int* arr, int* color, Vector3 pos, Vector3 dim, Vector3 rot, float camDist, int width, int height) {
    Vector3_class p1 = Vector3_class(&pos);
    Vector3_class p2 = Vector3_class();

    p2.x = p1.x + dim.x;
    p2.y = p1.y;
    p2.z = p1.z;

    p1 = p1 * projection(camDist, p1.z);
    p2 = p2 * projection(camDist, p2.z);

    Vector2 _p1 = Vector2(p1.x, p1.y);
    Vector2 _p2 = Vector2(p2.x, p2.y);

    drawLine_cpp(arr, color, _p1, _p2, 4, width, height);
}
