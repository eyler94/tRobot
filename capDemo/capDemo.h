#include <Adafruit_CircuitPlayground.h>

void capRead() {
  uint16_t capVal{0};
  Serial.print("Reading: ...");
  capVal = CircuitPlayground.readCap(A7);
  Serial.println(capVal);
}
