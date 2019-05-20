
// TEC in use: http://www.hebeiltd.com.cn/peltier.datasheet/TEC1-12710.pdf
// Switch in use: http://www.unisonic.com.tw/datasheet/30N06.pdf
// control designed for a TIP120

#include <Arduino.h>
#include "tec.h"

void tec_setup() {
  pinMode(CTRL_PIN, OUTPUT);
}

void set_tec_voltage(int v) {
  if (v > 3.3) {
    v = 3.3;
  } else if (v < 0) {
    v = 0;
  } else {
    v = v * 256 / 3.3;
  }
  analogWrite(CTRL_PIN, v);
}
