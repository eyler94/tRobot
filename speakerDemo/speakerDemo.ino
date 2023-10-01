#include "speakerDemo.h"

uint16_t userTone{220};
uint16_t playTimeMs{125};

// Mario underground: 261 130 220 110 233 117                 @ 125 ms w/ 5 ms delay
// Power on         : 130 146 164 164 174 196 196 220 246 261

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  powerUp();
//  antennaSong();
  laserSong();
  delay(1000);
}
