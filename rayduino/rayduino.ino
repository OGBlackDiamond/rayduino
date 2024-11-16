#include "renderer.h"
#include "sphere.h"
#include "shape.h"

void setup() {
  Serial.begin(9600);
  Serial.println("code began");
  Renderer renderer(96, 64);
  Serial.println("construction finished");
  Sphere sphere(0.0, 0.0, -1.0, 10, 10, 30, 0.5);
  renderer.addSphere(sphere);
  delay(1000);
  renderer.castRays();
}

void loop() {
  // put your main code here, to run repeatedly:

}
