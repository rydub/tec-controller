#include "PID.h"

bool debug_mode = true;
float set_val = 1;

void setup() {
  if (debug_mode) Serial.begin(9600);
  PID_setup(set_val, debug_mode);
}

void loop() {
  run_PID(2);
  delay(1000);
  run_PID(1.5);
  delay(1000);
  run_PID(2);
  delay(1000);
  run_PID(1.5);
  delay(1000);
}
