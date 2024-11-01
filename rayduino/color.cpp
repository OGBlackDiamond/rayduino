#include "color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(const Color& rhs) {
    deepCopy(rhs.r, rhs.g, rhs.b);
}

Color::Color(int r, int b, int g) {
    deepCopy(r, g, b);
}

Color& Color::operator=(const Color& color) {
    deepCopy(color.r, color.g, color.b);
    return *this;
}

uint16_t Color::asBytes() {
    return (r << 11) | (g << 5) | b;
}

void Color::deepCopy(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}


