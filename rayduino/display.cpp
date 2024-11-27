#include "display.h"

Display::Display() {
    resX = 96;
    resY = 64;
    initializeDisplay();
    generateBuffer(96, 64);
}

Display::Display(int x, int y) {
    resX = x;
    resY = y;

    initializeDisplay();
}

Display::~Display() {
    for (int i = resY; i > 0; --i) {
        delete[] buffer[i];
    }
    delete[] buffer;
}


void Display::generateBuffer(int x, int y) {
  
}

void Display::setPixel(int x, int y, Color color) {
    buffer[y][x] = color;
}

void Display::renderDisplay() {
    for (int i = 0; i < resY; i++) {
        for (int j = 0; j < resX; j++) {
            uint16_t pixelColor = buffer[i][j].asBytes();
            //sendData((uint8_t) pixelColor);
            //sendData((uint8_t) pixelColor << 8);
        }
    }
}

int Display::initializeDisplay() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error Initializing SDL" << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("RayTracer", 
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              resX, resY, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cout << "Error creating window" << std::endl;
        return 1;
    }

    winSurface = SDL_GetWindowSurface(window);


    if (!winSurface) {
        std::cout << "Error getting surface" << std::endl;
        return 1;
    }

    SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));

    SDL_UpdateWindowSurface(window);

    return 0;
}
