#include <Adafruit_CircuitPlayground.h>

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  pinMode(A4, INPUT_PULLDOWN);
  pinMode(A5, INPUT_PULLDOWN);
  pinMode(A6, INPUT_PULLDOWN);
  pinMode(A7, INPUT_PULLDOWN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(A4)) {
    for (int pixelID=0;pixelID<10;pixelID++) {
      CircuitPlayground.setPixelColor(pixelID,0,200,0);    
    }
  }
  else if (digitalRead(A5)) {
    for (int pixelID=0;pixelID<10;pixelID++) {
      CircuitPlayground.setPixelColor(pixelID,0,0,200);    
    }    
  }
  else if (digitalRead(A6)) {
    for (int pixelID=0;pixelID<10;pixelID++) {
      CircuitPlayground.setPixelColor(pixelID,200,200,0);    
    }    
  }
  else if (digitalRead(A7)) {
    for (int pixelID=0;pixelID<10;pixelID++) {
      CircuitPlayground.setPixelColor(pixelID,200,0,0);    
    }    
  }
  else { //A4 == LOW
    for (int pixelID=0;pixelID<10;pixelID++) {
      CircuitPlayground.setPixelColor(pixelID,0,0,0);    
    }
  }
}
