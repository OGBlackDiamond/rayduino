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

Vector3::Vector3(const Vector3& rhs) {
    deepCopy(rhs.x, rhs.y, rhs.z);
}

Vector3& Vector3::operator=(const Vector3& rhs) {
    deepCopy(rhs.x, rhs.y, rhs.z);
    return *this;
}

void Vector3::deepCopy(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::normalize() {
    if (x + y + z == 0) {return;}
    float length = sqrt(x*x + y*y + z*z); 
    x /= length;
    y /= length;
    z /= length;
}
