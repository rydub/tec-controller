//LCD 1602A Screen test
//Reference: http://www.dreamdealer.nl/tutorials/connecting_a_1602a_lcd_display_and_a_light_sensor_to_arduino_uno.html

//lcd is instantiated in lcd.cpp

#include "lcd.h"

void setup() {
  lcd_setup();
}

void loop() {
  lcd_println(0, "new message 1");
  delay(1000);
  lcd_println(1, "new message 2");
  delay(1000);
}
