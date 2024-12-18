#include "sphere.h"

Sphere::Sphere(): Shape(){
    radius = 5;
}

Sphere::Sphere(Vector3 position, Surface surface, float rad)
    : Shape(position, surface) {
    radius = rad;
}

Sphere::Sphere(const Sphere& rhs) 
    : Shape(rhs){
    radius = rhs.radius;
}

HitInfo Sphere::checkCollision(Ray ray) {
    ray.normalize();

    Vector3 oc = position - ray.getPosition();
    Vector3 rayDir = ray.getDirection();

    float a = rayDir.length_squared();
    float b = dot(oc, rayDir);
    float c = oc.length_squared() - radius * radius;
    
    float dis = b * b - a * c;

    HitInfo thisHit;


    if (dis >= 0) {
        float distance = (b - sqrt(dis)) / a;
        if (distance > 0) {
            thisHit.didHit = true;
            thisHit.distance = distance;
            thisHit.hitPoint = ray.at(distance);
            thisHit.normal = thisHit.hitPoint - position; thisHit.normal.normalize();
        }
    }
    return thisHit;
}
