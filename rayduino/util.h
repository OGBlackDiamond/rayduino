#ifndef UTIL_H
#define UTIL_H

#include "Arduino.h"
#include "vector.h"

class Util {
public:
    static float randomValue(uint32_t);
    static float randomNormalValue(int);
    static Vector3 randomDirection(int);

    static int sign(float);
};

#endif
