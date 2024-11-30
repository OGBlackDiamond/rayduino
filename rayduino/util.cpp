#include "util.h"

float Util::randomValue(uint& seed) {
    seed = seed * 747796405 + 2891336453;
    uint result = ((seed >> ((seed >> 28) + 4)) ^ seed) * 277803737;
    result = (result >> 22) ^ result;
    return result / 4294967295.0;
}

float Util::randomNormalValue(uint& seed) {
    float theta = 2 * 3.1415926 * randomValue(seed);
    float rho = sqrt(-2 * log10(randomValue(seed)));
    return rho * cos(theta);
}

Vector3 Util::randomDirection(uint& seed) {
    float x = randomNormalValue(seed);
    float y = randomNormalValue(seed);
    float z = randomNormalValue(seed);
    Vector3 direction(x, y, z);
    return unit_vector(direction);
}

int Util::sign(float num) {
    return (num>0)-(num<0);
}
