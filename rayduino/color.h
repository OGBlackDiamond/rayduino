#ifndef COLOR_H
#define COLOR_H

#include "Arduino.h"

struct Color {
    float r;
    float g;
    float b;
    float light;
    Color();
    Color(float, float, float);
    Color(float, float, float, float);
    Color(const Color&);
    Color& operator=(const Color&);
    Color& operator+=(const Color&);
    Color& operator*=(const Color&);
    Color& operator*=(const float);
    Color& operator/=(const float);
    uint16_t asBytes();
private:
    void deepCopy(float, float, float, float);
};

inline Color operator*(const Color& base, const Color& multiple) {
    return Color(
        base.r * multiple.r,
        base.g * multiple.g,
        base.b * multiple.b
    );
}

inline Color operator*(const Color& base, const float multiple) {
    return Color(
        base.r * multiple,
        base.g * multiple,
        base.b * multiple
    );
}
#endif
