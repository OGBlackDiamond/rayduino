#ifndef RENDERER_H
#define RENDERER_H

#include "vector.h"

class Renderer {
public:
    Renderer();
    Renderer(int, int);

private:

    float depth = 10;
    
    Vector3 projectionPlane;

};

#endif
