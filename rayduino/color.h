#ifndef COLOR_H
#define COLOR_H

#include "Arduino.h"

struct Color {
    int r;
    int g;
    int b;
    Color();
    Color(int, int, int);
    Color(const Color&);
    Color& operator=(const Color&);
    uint16_t asBytes();
private:
    void deepCopy(int, int, int);
};

#endif
