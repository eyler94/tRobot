#include <Adafruit_CircuitPlayground.h>

void powerUp() {
  uint8_t songLength{10};
  uint16_t song[songLength] = {130, 146, 164, 164, 174, 196, 196, 220, 246, 261};
  uint16_t playTimeMs{75};
  for (int noteSpot=0;noteSpot<songLength;noteSpot++) {
    CircuitPlayground.playTone(song[noteSpot], playTimeMs, true);
  }

}

void antennaSong() {
  uint8_t songLength{3};
  uint16_t song[songLength] = {130, 164, 196};
  uint16_t playTimeMs{45};
  for (int iteration=0;iteration<3;iteration++) {
    for (int noteSpot=0;noteSpot<songLength;noteSpot++) {
      CircuitPlayground.playTone(song[noteSpot]*(iteration+1), playTimeMs, true);
    }  
    for (int noteSpot=2;noteSpot>=0;noteSpot--) {
      CircuitPlayground.playTone(song[noteSpot]*(iteration+1), playTimeMs, true);
    }  
  }
}

void laserSong() {
  uint8_t songLength{9};
  uint16_t song[songLength] = {261, 293, 329, 349, 392, 493, 523, 523, 523};
  uint16_t playTimeMs{50};
  for (int noteSpot=0;noteSpot<songLength;noteSpot++) {
    CircuitPlayground.playTone(song[noteSpot], playTimeMs, true);
  }  
}

void motorSong() {
//  uint8_t songLength{9};
//  uint16_t song[songLength] = {261, 293, 329, 349, 392, 493, 523, 523, 523};
  uint16_t playTimeMs{250};
  for (int note=65;note<77;note++) {
    CircuitPlayground.playTone(note, playTimeMs, true);
//    delay(playTimeMs);
  }  
}
