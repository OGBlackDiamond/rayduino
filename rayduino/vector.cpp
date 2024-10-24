#include "vector.h"

Vector3::Vector3() {
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::normalize() {
    float length = sqrt(x*x + y*y + z*z); 
    x /= length;
    y /= length;
    z /= length;
}
