#include "Arduino.h"

#include "renderer.h"
#include "sphere.h"

Renderer renderer = Renderer();

void setup() {
  // put your setup code here, to run once:
  renderer.addShape(Sphere());
  renderer.castRays();
  renderer.display.renderDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:

}
