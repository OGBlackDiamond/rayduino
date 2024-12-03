#include "renderer.h"
#include "sphere.h"
#include "surface.h"

int main() {
    Renderer renderer(500, 500);
    Sphere sphere1(
        Vector3(0.5, 0, -2.0),
        Surface(1, 0.2, 0.2),
    0.5);
    Sphere sphere2(
        Vector3(-0.5, 0, -2.0),
        Surface(0.2, 0.2, 1),
    0.5);
    Sphere sphere3(
        Vector3(-1.5, 0.5, -1.0),
        Surface(0.2, 1, 0.2),
    1);
    Sphere sphere4(
        Vector3(1.5, 0.5, -1.0),
        Surface(
            Color(1, 1, 1),
            Color(0, 0, 0),
            0,
            1
        ),
    1);
    Sphere ground(
        Vector3(0, -100.5, 1.0),
        Surface(1.0, 1, 1.0),
    100);
    Sphere sun(
        Vector3(55, 35, -45.0),
        Surface(
            Color(0, 0, 0),
            Color(1, 1, 1),
            2,
            2
        ),
    65);

    renderer.addSphere(sphere1);
    renderer.addSphere(sphere2);
    renderer.addSphere(sphere3);
    renderer.addSphere(sphere4);
    renderer.addSphere(ground);
    renderer.addSphere(sun);


    renderer.castRays();
    std::cout << "Finished" << std::endl;
    renderer.display->renderDisplay();

    return 0;
}
