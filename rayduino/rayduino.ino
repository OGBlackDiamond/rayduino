#include "renderer.h"
#include "sphere.h"


void setup() {
  Serial.begin(9600);
  Serial.println("code began");
  Renderer renderer(96, 64);
  Serial.println("construction finished");
  // put your setup code here, to run once:
  //renderer.addShape(Sphere(0.0, 0.0, 1.0, 20, 20, 20, 1.0));
  delay(1000);
  renderer.castRays();
}

void loop() {
  // put your main code here, to run repeatedly:

}