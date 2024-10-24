#ifndef VECTOR_H
#define VECTOR_H

#include "Arduino.h"

struct Vector3 {
    float x;
    float y;
    float z;

    Vector3();
    Vector3(float, float, float);
    void normalize();
};

#endif
