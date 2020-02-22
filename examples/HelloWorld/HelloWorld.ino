/*
  LiquidCrystalRUS Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin 


*/

// include the library code:
#include <LiquidCrystalRUS.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
enum{rs = 7, en, d4, d5, d6, d7};
LiquidCrystalRUS lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(F("Cъешь ещё этих мягких французских булок "));
  lcd.setCursor(0, 1);
  lcd.print(F("да выпей чаю. С начала прошло "));
  
}

void loop() {
  lcd.setCursor(30, 1);
  lcd.print(word(millis() / 1000));
  lcd.print(" сек");
  delay(500);
 lcd.scrollDisplayLeft();
}
