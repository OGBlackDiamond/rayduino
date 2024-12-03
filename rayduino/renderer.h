#ifndef RENDERER_H
#define RENDERER_H

#include "hitInfo.h"
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

    const float depth = 2;

    const int maxBounceCount = 30;
    const int raysPerPixel = 10;
    
    Vector3 projectionPlane;

    Vector3 cameraCenter = Vector3(0, 0, 10);

    const float aspectRatio = 1000.0 / 1000.0;
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

    Color traceRay(Ray, uint&);
    
    HitInfo calcRayCollision(Ray);

};
#endif
