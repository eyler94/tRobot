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

void laser() {
  //RGB info
  uint8_t maxVal{200};
  uint8_t redVal{0};
  uint8_t greenVal{0};
  uint8_t blueVal{0};

  //Noise info
  uint8_t songLength{9};
//  uint16_t song[songLength] = {130, 147, 165, 175, 196, 220, 262, 262, 262};
  uint16_t song[songLength] = {261, 293, 329, 349, 392, 493, 523, 523, 523};
  uint16_t playTimeMs{50};

  for (uint8_t step=0; step<6; step++) {
    CircuitPlayground.playTone(song[step], playTimeMs, false);
    Serial.print(step);
    Serial.print(": ");
    Serial.println(song[step]);
    redVal = 30 * step;
    turnOnLEDS(redVal, greenVal, blueVal);
    delay(20);
  }
  redVal = maxVal;
  for (uint8_t step=6;step<9; step++) {
    turnOnLEDS(redVal, greenVal, blueVal);
    CircuitPlayground.playTone(song[step], playTimeMs, true);
    Serial.print(step);
    Serial.print(": ");
    Serial.println(song[step]);
    delay(20);
    turnOffLEDS();
    delay(20);   
  }
}
