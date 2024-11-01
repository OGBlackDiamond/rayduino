#include "util.h"

float Util::dot(Vector3 vec1, Vector3 vec2) {
    vec1.normalize(); vec2.normalize();
    return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
}
