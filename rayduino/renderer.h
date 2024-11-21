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

    const float depth = 1;

    const int maxBounceCount = 50;
    const int raysPerPixel = 500;
    
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

    Color traceRay(Ray&, uint32_t&);
    
    HitInfo calcRayCollision(Ray);

};
#endif
