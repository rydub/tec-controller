#ifndef lcd_h
#define lcd_h

#define RS 35
#define E  36
#define D7 37
#define D6 38
#define D5 17
#define D4 16

void lcd_setup();

void lcd_println(int line, char* msg);

#endif
