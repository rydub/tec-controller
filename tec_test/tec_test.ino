// Developed for Teensy3.6
// Link to DUT found in "tec.cpp"
#include "tec.h"
#include "lcd.h"

uint32_t safety_t = 0;
int incoming_byte = 0;
bool new_data = false;

void setup() {
  Serial.begin(9600);
  tec_setup();
  set_tec_voltage(0);
  Serial.println("Set up complete");
}

//void loop() {
//  digitalWrite(CTRL_PIN, HIGH);
//  delay(1000);
//  digitalWrite(CTRL_PIN, LOW);
//  delay(1000);
//}
void loop() {
  serial_read();
  if(new_data) {
    set_tec_val(incoming_byte);
    safety_t = micros();
  } else {
    if (micros() - safety_t > 1e7) {
      Serial.println("Timeout triggered, resetting pin");
      set_tec_voltage(0);
      safety_t = micros();
    }
  }
  delay(1000);
}

void serial_read() {
  if (Serial.available() > 0) {
    new_data = true;
    Serial.println("Before read, buffer size is: " + String(Serial.available()));
    incoming_byte = Serial.parseInt();
    Serial.read();
    Serial.println("Incoming byte is: " + String(incoming_byte));
    Serial.println("After read, buffer size is: " + String(Serial.available()));
  } else {
    new_data = false;
  }
}
