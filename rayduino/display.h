#ifndef DISPLAY_H
#define DISPLAY_H

#include "Arduino.h"
#include "color.h"

class Display {
public:
    Display();
    Display(int, int);
    ~Display();

    void setPixel(int, int, Color);

    void renderDisplay();

private:
    int resX;
    int resY;

    const uint8_t clock = 13;
    const uint8_t data = 11;
    const uint8_t reset = 9;
    const uint8_t command = 8;
    const uint8_t cs = 10;

    Color** buffer;

    void initializeDisplay();
    void generateBuffer();

    void sendData(uint8_t);
};

#endif
