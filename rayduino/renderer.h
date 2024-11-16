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

    void addSphere(Sphere);

    void castRays();
private:

    Sphere* spheres;

    float const depth = 1.0;
    
    Vector3 projectionPlane;

    Vector3 cameraCenter;

    const float aspectRatio = 3.0 / 2.0;
    const float viewPortHeight = 2.0;
    float viewPortWidth;

    Vector3 viewPortU;
    Vector3 viewPortV;

    Vector3 pixelDeltaU;
    Vector3 pixelDeltaV;

    Vector3 viewPortUpperLeft;

    Vector3 pixel00Loc;

    int numShapes;
    int maxShapes;

};
#endif
