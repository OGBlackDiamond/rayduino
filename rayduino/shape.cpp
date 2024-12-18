#include "shape.h"

Shape::Shape() {
    position = Vector3();
    surface = Surface();
}

Shape::Shape(Vector3& position, Surface& surface) {
    this->position = position;
    this->surface = surface;
}

Shape::Shape(const Shape& rhs) {
    surface = rhs.surface;
    position = rhs.position;
}

void Shape::setSurface(Surface surface) {this->surface = surface;}
void Shape::setPosition(Vector3 position) {this->position = position;}

Surface& Shape::getSurface() {return surface;}
Vector3& Shape::getPosition() {return position;}

