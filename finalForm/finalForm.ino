#include "finalForm.h"

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
//  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bootUp();
  delay(250);
  antenna();
  delay(250);
  laser();
  delay(250);
  motor();
  delay(250);
}
