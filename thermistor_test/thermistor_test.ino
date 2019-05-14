// Link to DUT is found in thermistor.cpp
// Last modified : 5.14.19 : R.Williams

#include "thermistor.h"

void setup() {
  Serial.begin(9600);
  t_setup(true);
}

void loop() {
  double t = read_t();
  Serial.println("Temp is: " + String(t));
  delay(1000);
}
