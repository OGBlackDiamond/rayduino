#ifndef VECTOR_H
#define VECTOR_H

#include "Arduino.h"

struct Vector3 {
    float x;
    float y;
    float z;

    Vector3();
    Vector3(float, float, float);
    Vector3(const Vector3&);
    Vector3& operator=(const Vector3&);
    void deepCopy(float, float, float);
    void normalize();
};

#endif
