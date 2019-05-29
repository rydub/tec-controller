#ifndef PID_h
#define PID_h

#define KP 90
#define KI 30
#define KD 80

void PID_setup(float target_val, bool mode=false);

float get_target_val();

void set_target_val(float val);

int run_PID(float val);

void pid_report();

#endif
