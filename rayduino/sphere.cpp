#include "sphere.h"

Sphere::Sphere(): Shape(){
    radius = 1;
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

bool Sphere::checkCollision(Ray& ray) {
    ray.normalize();

    Vector3 rayPos = ray.getPosition();
    Vector3 rayDir = ray.getPosition();

    float dx = rayDir.x - rayPos.x;
    float dy = rayDir.y - rayPos.y;
    float dz = rayDir.z - rayPos.z;


    float a = dx*dx + dy*dy + dz*dz;
    float b = 2*dx*(rayPos.x - position.x) + 2*dz*(rayPos.z - position.z);
    float c = position.x*position.x + position.y*position.y + position.z*position.z
        + rayPos.x*rayPos.x + rayPos.y*rayPos.y + rayPos.z*rayPos.z + 
        (-2*(position.x*rayPos.x + position.y * rayPos.y + position.z*rayPos.z) - radius * radius);

    float discriminant = b * b - 4 * a * c;

    return discriminant >= 0;
}
