#include <Adafruit_CircuitPlayground.h>

uint16_t userTone{220};
uint16_t playTimeMs{2000};

// Mario underground: 261 130 220 110 233 117                 @ 125 ms w/ 5 ms delay
// Power on         : 130 146 164 164 174 196 196 220 246 261

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(9600);
  Serial.println("Please type the tone in hz you'd like to hear: ");
//  CircuitPlayground.playTone(userTone, playTimeMs, false);
}

void loop() {
  // put your main code here, to run repeatedly:
  userTone = Serial.parseInt();
  CircuitPlayground.playTone(userTone, playTimeMs, false);
  delay(5);
}
