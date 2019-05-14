#include <Arduino.h>
#include "thermistor.h"

//thermistor in use: https://www.omega.com/en-us/search/?text=ON-909-44006

bool debug_t = false; 

void t_setup (bool mode) {
  debug_t = mode;
  pinMode(T_PIN, INPUT);
  analogReference(EXTERNAL);       // Reference should come from 3.3V rail for noise mitigation
}

double adc2volt(uint16_t adc_val) {
  return 5.0 / 1023 *adc_val;
}

double volt2res(double v_val) {
  return R_REF / ((5.0 / v_val) - 1);
}

double res2cel(double r_val) {
  // Values for 10k thermistor. ref: https://www.skyeinstruments.com/wp-content/uploads/Steinhart-Hart-Eqn-for-10k-Thermistors.pdf
  float a = 0.0011253088;
  float b = 0.0002347118;
  float c = 0.0000000856;
  return 1 / (a + b * log(r_val) + c * pow(log(r_val), 3.0)) - 273.15;
}

double read_t() {
  double t_sum = 0;
  for (int i = 0; i < NUM_SAMPS; i++) {
    uint16_t t_adc = analogRead(T_PIN);
    double t_v = adc2volt(t_adc);
    double t_r = volt2res(t_v);
    t_sum += res2cel(t_r);
  }
   return t_sum / NUM_SAMPS;
}
