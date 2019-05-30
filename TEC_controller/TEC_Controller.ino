// TEC/Peltier Cooler Controller for use in thermal environment stabilization.
// Built for Teensy3.6, devices in use documented in the appropriate driver files
#include "tec.h"
#include "thermistor.h"
#include "PID.h"
#include "lcd.h"

bool debug_mode = true;

double current_temp = 0;
uint8_t line = 0;

void report(char* msg) {
  if (debug_mode) {
    Serial.println(msg);
  } else {
    lcd_println(0,  msg);
  }
}

void setup() {
  PID_setup(0, debug_mode);
  // SET TARGET VAL //
  set_target_val(16);
  t_setup(debug_mode);
  tec_setup(debug_mode);
  Serial.begin(9600);
  lcd_setup();
  report("Initialized");
}

void loop() {
  current_temp = read_t();
  if (debug_mode) Serial.println("#######Current Temp#########");;
  Serial.println("Temp (C): " + String(current_temp));
  uint8_t pid_val = run_PID(current_temp);
  set_tec_voltage(pid_val);
  pid_report();
  delay(1000);
}
