#include "shape.h"

Shape::Shape() {
    position = Vector3();
    color = Color();
}

Shape::Shape(float x, float y, float z, int r, int g, int b) {
    position = Vector3(x, y, z);
    color = Color(r, g, b);
}

Shape::Shape(Vector3& position, Color& color) {
    this->position = position;
    this->color = color;
}

Shape::Shape(const Shape& rhs) {
    color = rhs.color;
    position = rhs.position;
}

Shape::~Shape() {}

void Shape::setColor(Color color) {this->color = color;}
void Shape::setPosition(Vector3 position) {this->position = position;}

Color& Shape::getColor() {return color;}
Vector3& Shape::getPosition() {return position;}

