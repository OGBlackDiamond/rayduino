#ifndef HITINFO_H
#define HITINFO_H

#include "vector.h"

struct HitInfo {
    bool didHit = false;
    float distance;
    Vector3 hitNormal;
    Vector3 normal;
};

#endif
