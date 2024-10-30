#ifndef SPHERE_H
#define SPHERE_H 

#include "shape.h"
#include "ray.h"

class Sphere: Shape {
private:
    float radius;

public:
    Sphere();
    Sphere(float, float, float, int, int, int, float);
    Sphere(Vector3&, Color&, float);
    Sphere(const Sphere&);

    bool checkCollision(Ray&);
};
#endif
