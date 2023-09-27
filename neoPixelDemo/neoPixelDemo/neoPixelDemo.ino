#include "tRobot.h"

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  bootUp();
  delay(500);
  antenna();
  delay(500);
  laser();
  delay(500);
  motor();
}
