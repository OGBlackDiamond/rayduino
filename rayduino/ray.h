#ifndef RAY_H
#define RAY_H

#include "color.h"
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

    Vector3 at(double);

    void normalize();

    Color color;
    
private:
    Vector3 position;

    Vector3 direction;

};

#endif 
