#ifndef SURFACE_H
#define SURFACE_H

#include "color.h"

#include <iostream>

class Surface {
public:
    Color surfaceColor;
    Color emissionColor;
    float emissionStrength;
    float smoothness;

    Surface(Color surfaceColor, Color emissionColor, float emissionStrength, float smoothness) {
        this->surfaceColor = surfaceColor;
        this->emissionColor = emissionColor;
        this->emissionStrength = emissionStrength;
        this->smoothness = smoothness;
    } 

    Surface(float r, float b, float g) {
        surfaceColor = Color(r, g, b);
        emissionColor = Color(0, 0, 0);
        emissionStrength = 0.0;
        smoothness = 0.0;
    }

    Surface() {
        surfaceColor = Color(1, 1, 1);
        emissionColor = Color(0, 0, 0);
        emissionStrength = 0.0;
        smoothness = 0.0;
    }

    Surface& operator=(const Surface& rhs) {
        this->surfaceColor = rhs.surfaceColor;
        this->emissionColor = rhs.emissionColor;
        this->emissionStrength = rhs.emissionStrength;
        this->smoothness = rhs.smoothness;
        return *this;
    }
    
};

#endif
