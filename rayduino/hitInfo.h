#ifndef HITINFO_H
#define HITINFO_H

#include "surface.h"
#include "vector.h"

struct HitInfo {
    bool didHit = false;
    float distance = -1;
    Vector3 hitPoint = Vector3();
    Vector3 normal = Vector3();
    Surface shapeSurface = Surface();
};

#endif
