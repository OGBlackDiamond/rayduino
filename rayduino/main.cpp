#include "renderer.h"
#include "sphere.h"

int main() {
    Renderer renderer(500, 500);
    Sphere sphere1(0.5, 0, -2.0, 1, 0.2, 0.2, 0.5);
    Sphere sphere2(-0.5, 0, -2.0, 0.2, 0.2, 1, 0.5);
    Sphere sphere3(-1.5, 0.5, -1.0, 0.2, 1, 0.2, 1);
    Sphere sphere4(1.5, 0.5, -1.0, 0.1, 0.1, 0.1, 1);
    Sphere ground(
        Vector3(0, -100.5, 1.0),
        Color(0.0, 0, 0.0, 1)
        , 100);
    /*
    Sphere sun(
        Vector3(55, 35, -45.0),
        Color(0, 0, 0, 2.5),
        65 
    );
    */

    renderer.addSphere(sphere1);
    renderer.addSphere(sphere2);
    renderer.addSphere(sphere3);
    renderer.addSphere(sphere4);
    renderer.addSphere(ground);
    //renderer.addSphere(sun);


    renderer.castRays();
    std::cout << "Finished" << std::endl;
    renderer.display->renderDisplay();

    return 0;
}
