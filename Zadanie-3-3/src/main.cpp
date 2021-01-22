#include <Arduino.h>
#include <LiquidCrystal.h>
#include <stdio.h>

int stanPrzycisku = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int hh1, mm1, ss1, hh2, mm2, ss2;
char czas1[16];
char czas2[16];

void setup() {
  lcd.begin(16, 2);
  pinMode(7, INPUT);
}

void loop() {
  stanPrzycisku = digitalRead(7);
  if (stanPrzycisku == HIGH) {
    ss2++;
    if (ss2 == 60)
    {
      ss2 = 0;
      mm2++;
      if (mm2 == 60)
      {
        mm2 = 0;
        hh2++;
      }
    }
  }
  
  ss1++;
  
  if (ss1 == 60)
  {
    ss1 = 0;
    mm1++;
    if (mm1 == 60)
    {
      mm1 = 0;
      hh1++;
    }
  }
  
  lcd.setCursor(0, 0);
  lcd.print(hh2);
  lcd.print(" : ");
  lcd.print(mm2);
  lcd.print(" : ");
  lcd.print(ss2);
  lcd.setCursor(0, 1);
  lcd.print(hh1);
  lcd.print(" : ");
  lcd.print(mm1);
  lcd.print(" : ");
  lcd.print(ss1);
  delay(10);
}