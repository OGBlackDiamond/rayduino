#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

#include "vector.h"

class Util {
public:
    static float randomValue(uint&);
    static float randomNormalValue(uint&);
    static Vector3 randomDirection(uint&);

    static int sign(float);
};

#endif
