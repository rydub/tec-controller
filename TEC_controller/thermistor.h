#ifndef thermistor_h
#define thermistor_h

#define T_PIN A14        // Thermistor sampling pin
#define NUM_SAMPS 5     // Number of samples to average per reading
#define R_REF 10000     // reference resistor for voltage divider

void t_setup (bool mode);

double adc2volt(uint16_t adc_val);

double volt2res(double v_val);

double res2cel(double r_val);

double read_t();

#endif
