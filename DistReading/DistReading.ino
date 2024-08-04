#include <LiquidCrystal.h>
#include "SR04.h"

#define TRIG_PIN 2
#define ECHO_PIN 4

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distNum;

void setup() {
  // put your setup code here, to run once:
  // UltraSonic Sensor:  
  Serial.begin(9600);
  delay(1000);

  // LCD Init:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  distNum = sr04.Distance();

  // LCD Display:
  lcd.setCursor(0, 0);
  lcd.print("Dist         CM ");
  lcd.setCursor(6, 0);
  lcd.print(distNum);
  delay(500);
}
