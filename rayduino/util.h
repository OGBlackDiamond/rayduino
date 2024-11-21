#ifndef UTIL_H
#define UTIL_H

#include "Arduino.h"
#include "vector.h"

class Util {
public:
    static float randomValue(uint32_t&);
    static float randomNormalValue(uint32_t&);
    static Vector3 randomDirection(Vector3, uint32_t&);

    static int sign(float);
};

#endif
