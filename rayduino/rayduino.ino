#include "renderer.h"
#include "sphere.h"


void setup() {
  Serial.begin(9600);
  Serial.println("code began");
  Renderer renderer(96, 64);
  Serial.println("construction finished");
  // put your setup code here, to run once:
  renderer.addShape(Sphere(0, 0, 10, 20, 20, 20, 10));
  renderer.castRays();
  renderer.display->renderDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:

}
