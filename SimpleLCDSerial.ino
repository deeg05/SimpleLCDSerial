/*
 * SimpleLCDSerial is little programm,what will display 
 * 
 * LCD wiring:
 * 
 * ------------------
 * RS|EN|D4|D5|D6|D7|
 * ------------------
 *  7| 6| 5| 4| 3| 2|
 * ------------------
*/

// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int i;
int val = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  i = 0;
}

void loop() {
//  if (Serial.available() > 0) {
    val = Serial.read();
    if (val > 31) lcd.write(val);
    if (val == 10) {
      i++;
      if (i>3) i=0;
      lcd.setCursor(0,i);
    }
}
