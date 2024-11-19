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
    uint16_t asBytes();
private:
    void deepCopy(float, float, float, float);
};

#endif
