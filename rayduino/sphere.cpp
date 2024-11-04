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

bool Sphere::checkCollision(Ray ray) {
    //ray.normalize();
    Serial.println(ray.getDirection().y);

    Vector3 rayPos = ray.getPosition();
    Vector3 rayDir = ray.getDirection();

    float dx = rayPos.x - position.x;
    float dz = rayPos.z - position.y;
    float dy = rayPos.y - position.z;

    Vector3 d(dx, dy, dz);

    float a = Util::dot(rayDir, rayDir);
    float b = 2.0 * Util::dot(d, rayDir);
    float c = Util::dot(d, d) - radius * radius;
    
    float dis = b * b - 4*  a * c;

    return dis >= 0;

}
