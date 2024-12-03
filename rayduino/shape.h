#ifndef SHAPE_H
#define SHAPE_H

#include "surface.h"
#include "vector.h"
#include "ray.h"
#include "hitInfo.h"

// this is an abstract class that all other shapes will inherit from
class Shape {
public:
    Shape();
    Shape(Vector3&, Surface&);
    Shape(const Shape&);

    void setSurface(Surface);
    void setPosition(Vector3);

    Surface& getSurface();
    Vector3& getPosition();
    
    // each shape should override this
    HitInfo checkCollision(Ray);

protected:

    Vector3 position;
    Surface surface;

};

#endif 
