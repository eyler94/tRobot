#include "finalForm.h"

#define greenButton A4
#define blueButton A5
#define yellowButton A6
#define redButton A7


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  pinMode(greenButton, INPUT_PULLDOWN);
  pinMode(blueButton, INPUT_PULLDOWN);
  pinMode(yellowButton, INPUT_PULLDOWN);
  pinMode(redButton, INPUT_PULLDOWN);
  bootUp();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(greenButton)) {
    bootUp();
  }
  else if (digitalRead(blueButton)) {
    motor();
  }
  else if (digitalRead(yellowButton)) {
    antenna();
  }
  else if (digitalRead(redButton)) {
    laser();
  }

// ////// Cycle through options
//  bootUp();
//  delay(250);
//  antenna();
//  delay(250);
//  laser();
//  delay(250);
//  motor();
//  delay(250);
}
