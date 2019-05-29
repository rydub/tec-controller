// PID Controller reference: http://www.electronoobs.com/eng_arduino_tut24_code3.php
// Adapted to run TEC1-12710 with a ON-909-44006 thermistor, links in corresponding driver files
// Parameter tuning is done in PID.h

#include "PID.h"
#include <Arduino.h>

bool debug_pid = false;
float target_val = 0;

float PID_err = 0;
float prev_err = 0;
float PID_value = 0;

int t = 0;
int prev_t = 0;

float p = 0; float i = 0; float d = 0;

void PID_setup(float target_val, bool mode=false) {
  t = millis();
  set_target_val(target_val);
  debug_pid = mode;
}

float get_target_val() {
  return target_val;
}

void set_target_val(float val) {
  target_val = val;
}

// In: Temp in C (float)
// Out: unsigned 8-bit PWM value for TEC current control, full range available
int run_PID(float val) {
  prev_err = PID_err;
  PID_err = (uint8_t) 10 * (val - target_val);
  
  prev_t = t;
  t = millis();
  
  //proportional term
  p = 0.01 * KP * PID_err;
  //integral term
  if (i >= 0 && i <  255) {
    i = i + (0.01 * KI * PID_err);
  } else {
    i = 0;
  }
  //derivative term
  //d = 0.01 * KD * (PID_err - prev_err) / (0.001 * (t - prev_t));
  d = 0;

  PID_value = p + i + d;
  
  //Ensure we are in the valid range for 8-bit analog writes.
  if(PID_value < 0) {
    PID_value = 0;
  }
  if(PID_value > 255) {
    PID_value = 255;
  }
  return PID_value;
}

void pid_report() {
  if (debug_pid) {
    Serial.println("###########PID State#############");
    Serial.println("Set Value: " + String(target_val));
    Serial.println("Error Value: " + String(PID_err));
    Serial.println("Cycle time: " + String(t - prev_t));
    Serial.println("p = " + String(p) + "\ni = " + String(i) + "\nd = " + String(d));
    Serial.println("Control signal = " + String(PID_value));
  }
}
