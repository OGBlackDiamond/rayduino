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

    Color getPixel(int, int);

    void renderDisplay();

    void sendColor(Color);

    int initializeDisplay();

private:
    int resX;
    int resY;

    Color** buffer;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Event curEvent;
    
    void generateBuffer(int, int);
};

#endif
