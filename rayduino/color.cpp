#include "color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(const Color& rhs) {
    deepCopy(rhs.r, rhs.g, rhs.b);
}

Color::Color(float r, float g, float b) {
    deepCopy(r, g, b);
}

Color& Color::operator=(const Color& color) {
    deepCopy(color.r, color.g, color.b);
    return *this;
}

uint16_t Color::asBytes() {
    return (((int)(r*31) << 11) | ((int)(g*63) << 5) | (int)(b*31));
}

void Color::deepCopy(float r, float g, float b) {
    this->r = r > 1 ? 1 : r;
    this->g = g > 1 ? 1 : g;
    this->b = b > 1 ? 1 : b;
}


