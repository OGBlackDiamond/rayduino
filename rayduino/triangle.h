#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public Shape {
private:
    Vector3 v1, v2, v3;

public:
    Triangle();
    Triangle(Vector3, Surface);
    Triangle(Vector3, Surface, Vector3, Vector3, Vector3);
    Triangle(const Triangle&);

    HitInfo checkCollision(Ray);
};

#endif

