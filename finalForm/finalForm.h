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
  //RGB info
  uint8_t redVal{0};
  uint8_t greenVal{200};
  uint8_t blueVal{0};

  //Noise info
  uint8_t playTimeMs{75};
  uint16_t song[10] = {130, 146, 164, 164, 174, 196, 196, 220, 246, 261};

  for(int pixelID=0;pixelID<10;pixelID++) {
    CircuitPlayground.setPixelColor(pixelID, redVal, greenVal, blueVal);
    CircuitPlayground.playTone(song[pixelID], playTimeMs, true);
  }
  flashLEDS(redVal, greenVal, blueVal);
}

void antenna() {
  //RGB info
  uint8_t redVal{100};
  uint8_t greenVal{100};
  uint8_t blueVal{0};
  uint8_t middleLow{2};
  uint8_t middleHigh{7};

  //Noise info
  uint8_t songLength{3};
  uint16_t song[songLength] = {130, 164, 196};
  uint16_t playTimeMs{45};

  for (int steps=0;steps<3;steps++) {
    CircuitPlayground.setPixelColor(middleLow+steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleLow-steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleHigh+steps, redVal, greenVal, blueVal);
    CircuitPlayground.setPixelColor(middleHigh-steps, redVal, greenVal, blueVal);
    for (int noteSpot=0;noteSpot<songLength;noteSpot++) {
      CircuitPlayground.playTone(song[noteSpot]*(steps+1), playTimeMs, true);
    }  
    for (int noteSpot=2;noteSpot>=0;noteSpot--) {
      CircuitPlayground.playTone(song[noteSpot]*(steps+1), playTimeMs, true);
    }  

//    delay(200);
  }
  flashLEDS(redVal, greenVal, blueVal);
}
