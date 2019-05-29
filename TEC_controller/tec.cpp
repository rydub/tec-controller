
// TEC in use: http://www.hebeiltd.com.cn/peltier.datasheet/TEC1-12710.pdf
// Switch in use: http://www.unisonic.com.tw/datasheet/30N06.pdf
// control designed for a TIP120

#include <Arduino.h>
#include "tec.h"

bool debug_tec = false;

void tec_setup(bool mode=false) {
  pinMode(CTRL_PIN, OUTPUT);
}

void set_tec_voltage(int v) {
  if (v > 3.3) {
    v = 3.3;
  } else if (v < 2) {
    v = 0;
  }
  v = v * 256 / 3.3;
  analogWrite(CTRL_PIN, v);
}

void set_tec_val(uint8_t val) {
  if (val > 255) {
    val = 255;
  } else if (val < 0) {
    val = 0;
  }
  analogWrite(CTRL_PIN, val);
}
