#include <Adafruit_CircuitPlayground.h>

void turnOffLEDS() {
  for(int pixelID=0;pixelID<=9;pixelID++) {
    CircuitPlayground.setPixelColor(pixelID, 0, 0, 0);
  }
}

void turnOnLEDS(uint8_t redVal, uint8_t greenVal, uint8_t blueVal) {
  for(int pixelID=0;pixelID<=9;pixelID++) {
    CircuitPlayground.setPixelColor(pixelID, redVal, greenVal, blueVal);
  }  
}

void flashLEDS(uint8_t redVal, uint8_t greenVal, uint8_t blueVal) {
  int delayTime{200};
  turnOnLEDS(redVal, greenVal, blueVal);
  delay(delayTime);
  turnOffLEDS();
  delay(delayTime);
  turnOnLEDS(redVal, greenVal, blueVal);
  delay(delayTime);
  turnOffLEDS();
  delay(delayTime);
  turnOnLEDS(redVal, greenVal, blueVal);
  delay(delayTime);
  turnOffLEDS();
  delay(delayTime);
  turnOnLEDS(redVal, greenVal, blueVal);
  delay(delayTime);
  turnOffLEDS();
}

void bootUp() {
  uint8_t redVal{0};
  uint8_t greenVal{200};
  uint8_t blueVal{0};
  uint8_t delayTime{125};
  for(int pixelID=0;pixelID<=9;pixelID++) {
    CircuitPlayground.setPixelColor(pixelID, redVal, greenVal, blueVal);
    delay(delayTime);
  }
  flashLEDS(redVal, greenVal, blueVal);
}

void antenna() {
  uint8_t redVal{100};
  uint8_t greenVal{100};
  uint8_t blueVal{0};
  uint8_t middleLow{2};
  uint8_t middleHigh{7};
  
  for (int steps=0;steps<3;steps++) {
    CircuitPlayground.setPixelColor(middleLow+steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleLow-steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleHigh+steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleHigh-steps, redVal, greenVal, blueVal);
//    delay(300-100*steps);
    delay(200);
  }
  flashLEDS(redVal, greenVal, blueVal);
}

void laser() {
  uint8_t maxVal{200};
//  uint8_t redVal{0};
  uint8_t greenVal{0};
  uint8_t blueVal{0};
  for (uint8_t redVal=0;redVal<=maxVal;redVal+=5) {
    turnOnLEDS(redVal, greenVal, blueVal);
    delay(20);
  }
  uint8_t redVal{maxVal};
  flashLEDS(redVal, greenVal, blueVal);
  turnOffLEDS();
}

void motor() {
  uint8_t redVal{0};
  uint8_t greenVal{0};
  uint8_t blueVal{200};
  uint8_t middleLow{2};
  uint8_t middleHigh{7};
  uint8_t maxLEDspot{10};
  for (int cycle=0;cycle<100;cycle++) {
    CircuitPlayground.setPixelColor((middleLow+cycle)%maxLEDspot, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor((middleHigh+cycle)%maxLEDspot, redVal, greenVal, blueVal);
    delay(50);
    turnOffLEDS();
  }
}
