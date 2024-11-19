#ifndef SPHERE_H
#define SPHERE_H 

#include "Arduino.h"
#include "shape.h"
#include "ray.h"
#include "util.h"

class Sphere: public Shape {
private:
    float radius;

public:
    Sphere();
    Sphere(float, float, float, float, float, float, float);
    Sphere(Vector3, Color, float);
    Sphere(const Sphere&);

    HitInfo checkCollision(Ray);
};
#endif
