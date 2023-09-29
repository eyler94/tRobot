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