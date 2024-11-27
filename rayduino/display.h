#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <iostream>

#include <SDL2/SDL.h>
#include "color.h"

class Display {
public:
    Display();
    Display(int, int);
    ~Display();

    void setPixel(int, int, Color);

    void renderDisplay();

    void sendColor(Color);

private:
    int resX;
    int resY;

    Color** buffer;

    SDL_Surface* winSurface = NULL;
    SDL_Window* window = NULL;
    
    int initializeDisplay();
    void generateBuffer(int, int);
};

#endif
