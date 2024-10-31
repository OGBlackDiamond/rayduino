#ifndef RENDERER_H
#define RENDERER_H

#include "vector.h"
#include "shape.h"

class Renderer {
public:
    Renderer();
    Renderer(int, int);
    ~Renderer();

    void addShape(Shape&);

private:

    float depth = 10;
    
    Vector3 projectionPlane;

    int numShapes;
    int maxShapes;
    Shape* shapes;

};

#endif
