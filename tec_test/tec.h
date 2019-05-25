#ifndef tec_h
#define tec_h

#define CTRL_PIN 14

void tec_setup();

uint8_t tec_volt2adc(float v);

void set_tec_voltage(int v);

void set_tec_val(uint8_t val);

#endif  
