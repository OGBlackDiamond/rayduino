#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray {
public:
    Ray();
    Ray(float, float, float, float, float, float);
    Ray(Vector3&, Vector3&);
    Ray(const Ray&);

    Ray& operator=(const Ray&);

    void setPosition(Vector3&);
    void setDirection(Vector3&);

    Vector3 getPosition();
    Vector3 getDirection();

    void normalize();
    
private:
    Vector3 position;

    Vector3 direction;
};

#endif 