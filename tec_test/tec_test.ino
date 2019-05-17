// Developed for Teensy3.6
// Link to DUT found in "tec.cpp"
#include "tec.h"

void setup() {
  tec_setup();
  randomSeed(analogRead(A0));
}

void loop() {
  int r = rand(1023);
  set_tec_voltage(r);
  delay(1000);
}
