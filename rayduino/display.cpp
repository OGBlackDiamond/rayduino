#include "display.h"
#include <SDL2/SDL_render.h>

Display::Display() {
    resX = 96;
    resY = 64;
    initializeDisplay();
    generateBuffer(96, 64);
}

Display::Display(int x, int y) {
    resX = x;
    resY = y;
    generateBuffer(x, y);
    initializeDisplay();
}

Display::~Display() {
    for (int i = resY; i >= 0; --i) {
        delete[] buffer[i];
    }
    delete[] buffer;
}


void Display::generateBuffer(int x, int y) {
    buffer = new Color*[y];
    for (int i = 0; i < y; i++) {
        buffer[i] = new Color[x];
    }
}

void Display::setPixel(int x, int y, Color color) {
    buffer[y][x] = color;
}

Color Display::getPixel(int x, int y) {return buffer[y][x];}

void Display::renderDisplay() {
    bool rendering = true;
    while (rendering) {

        while (SDL_PollEvent(&curEvent)) {
            if (curEvent.type == SDL_QUIT) {
                rendering = false;
            }
        }
        for (int i = 0; i < resY; i++) {
            for (int j = 0; j < resX; j++) {
                Color pixelColor = buffer[i][j];
                SDL_SetRenderDrawColor(renderer,
                                       pixelColor.r * 255.0,
                                       pixelColor.g * 255.0,
                                       pixelColor.b * 255.0,
                                       255);
                SDL_RenderDrawPoint(renderer, j, i);
            }
        }
        SDL_RenderPresent(renderer);
    }
}

int Display::initializeDisplay() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error Initializing SDL" << std::endl;
        return 1;
    }

    SDL_CreateWindowAndRenderer(resX, resY, 0, &window, &renderer);

    return 0;
}
