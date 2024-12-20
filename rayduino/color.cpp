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

Color::~Color() {}

Color& Color::operator=(const Color& color) {
    deepCopy(color.r, color.g, color.b);
    return *this;
}

Color& Color::operator+=(const Color& color) {
    r += color.r;
    g += color.g;
    b += color.b;
    return *this;
}

Color& Color::operator*=(const Color& color) {
    r *= color.r;
    g *= color.g;
    b *= color.b;
    return *this;
}

Color& Color::operator*=(const float color) {
    r *= color;
    b *= color;
    g *= color;
    return *this;
}

Color& Color::operator/=(const float num) {
    r /= num;
    b /= num;
    g /= num;
    return *this;
}

uint16_t Color::asBytes() {
    return (((int)(r*31) << 11) | ((int)(g*63) << 5) | (int)(b*31));
}

void Color::deepCopy(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}


