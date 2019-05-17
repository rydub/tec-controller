
// TEC in use: http://www.hebeiltd.com.cn/peltier.datasheet/TEC1-12710.pdf
// control designed for a TIP120

#include <Arduino.h>
#include "tec.h"

void tec_setup() {
  pinMode(CTRL_PIN, OUTPUT);
}

void set_tec_voltage(uint16_t v) {
  analogWrite(CTRL_PIN, v);
}
