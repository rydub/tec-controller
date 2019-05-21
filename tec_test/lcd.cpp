//LCD 1602A screen driver code
#include <LiquidCrystal.h>
#include "lcd.h"

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void lcd_setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("Initializing");
}
