#include "renderer.h"
#include "sphere.h"
#include "shape.h"

void setup() {
  Serial.begin(9600);
  Serial.println("code began");
  Renderer renderer(96, 64);
  Serial.println("construction finished");
  Sphere sphere(1.0, 3.0, -13.0, 1, 0.2, 0.2, 5);
  Sphere ground(1, -100, -20, 0.2, 1, 0.2, 100);
  Sphere sun(
        Vector3(550, 550, 850),
        Color(1, 1, 1, 1),
        250
  );
  renderer.addSphere(sphere);
  renderer.addSphere(ground);
  renderer.addSphere(sun);
  delay(1000);
  renderer.castRays();
}

void loop() {
  // put your main code here, to run repeatedly:

}
