#ifndef RENDERER_H
#define RENDERER_H

#include "vector.h"
#include "sphere.h"
#include "display.h"

class Renderer {
public:
    Renderer();
    Renderer(int, int);
    ~Renderer();

    Display* display;

    void addShape(Sphere&);

    void castRays();

private:

    float const depth = 60;
    
    Vector3 projectionPlane;


    int numShapes;
    int maxShapes;
    Sphere* shapes;

};

#endif
