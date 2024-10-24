#include "shape.h"

Shape::Shape() {
    color = Color();
}

Shape::Shape(float x, float y, float z, int r, int g, int b) {
    color = Color(r, g, b);
}

Shape::Shape(Color color) {
    setColor(color);
}

Shape::Shape(const Shape& rhs) {
    setColor(rhs.color); 
}

void Shape::setColor(Color color) {
    this->color = color;
}

void Shape::setPosition(Vector3 vector) {

}

Shape::deepCopy(float x, float y, float z, int r, int g, int b) {
    
}
