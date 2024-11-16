#include "sphere.h"

Sphere::Sphere(): Shape(){
    radius = 5;
}

Sphere::Sphere(float x, float y, float z, int r, int g, int b, float rad)
    : Shape(x, y, z, r, g, b) {
    radius = rad;
}

Sphere::Sphere(Vector3& position, Color& color, float rad)
    : Shape(position, color) {
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

    if (dis < 0) {
        thisHit.didHit = false;
    } else {
        return (b - sqrt(dis)) / a;
    }
    return thisHit;
}
