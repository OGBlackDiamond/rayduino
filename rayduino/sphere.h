#ifndef SPHERE_H
#define SPHERE_H 

#include <math.h>

#include "shape.h"
#include "ray.h"
#include "surface.h"

class Sphere: public Shape {
private:
    float radius;

public:
    Sphere();
    Sphere(Vector3, Surface, float);
    Sphere(const Sphere&);

    HitInfo checkCollision(Ray);
};
#endif
