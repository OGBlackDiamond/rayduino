#include "ray.h"

Ray::Ray() {
    position = Vector3(0, 0, 0);
    direction = Vector3(0, 0, 0);
    color = Color(1, 1, 1);
}

Ray::Ray(float x, float y, float z, float dx, float dy, float dz) {
    position = Vector3(x, y, z);
    direction = Vector3(dx, dy, dz);
    color = Color(1, 1, 1);

}

Ray::Ray(Vector3& position, Vector3& direction) {
    this->position = position;
    this->direction = direction;
    color = Color(1, 1, 1);
}

Ray::Ray(const Ray& rhs) {
    position = rhs.position;
    direction = rhs.direction;
    color = rhs.color;
}

Ray& Ray::operator=(const Ray& rhs) {
    position = rhs.position;
    direction = rhs.direction;
    color = rhs.color;
}

void Ray::setPosition(Vector3& pos) {
    position = pos;
}

void Ray::setDirection(Vector3& dir) {
    direction = dir;
}

Vector3 Ray::getPosition() {return position;}
Vector3 Ray::getDirection() {return direction;}

Vector3 Ray::at(double t) {
    return position + t*direction;
}

void Ray::normalize() {
    direction.normalize();
    position.normalize();
}
