#include "util.h"

float Util::randomValue(uint32_t seed) {
    uint32_t tmpSeed = seed * 747796405.0 + 2891336453.0;
    uint32_t result = ((seed >> ((seed >> 28) + 4)) ^ seed) * 277803737;
    result = (result >> 22) ^ result;
    return result  / 4292967295.0;
}

float Util::randomNormalValue(int seed) {
    float theta = 2 * 3.1415926 * randomValue(seed);
    float rho = sqrt(-2 * log10(randomValue(seed)));
    return rho * cos(theta);
}

Vector3 Util::randomDirection(int seed) {
    float x = randomNormalValue(seed);
    float y = randomNormalValue(seed);
    float z = randomNormalValue(seed);
    Vector3 direction = Vector3(x, y, z);
    direction.normalize();
    return direction;
}

int Util::sign(float num) {
    return (num>0)-(num<0);
}
