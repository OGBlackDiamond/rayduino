#ifndef RENDERER_H
#define RENDERER_H

#include "vector.h"
#include "sphere.h"
#include "display.h"
#include "util.h"

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

    float const depth = 1;
    
    Vector3 projectionPlane;

    Vector3 cameraCenter;

    const float aspectRatio = 96.0 / 64.0;
    const float viewPortHeight = 2;
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
