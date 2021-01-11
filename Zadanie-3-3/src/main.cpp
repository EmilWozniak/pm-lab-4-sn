#include <Arduino.h>
#include <LiquidCrystal.h>
#include <stdio.h>

// Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char rxBuff[32];
int ValueA = 0, ValueB = 0;
char operation[16];

void setup() {
    lcd.begin(16, 2); //Ustawienie liczby kolumn i wierszy
    lcd.print("2+2");
    Serial.begin(9600);
    Serial.setTimeout(3000);
    delay(2000);
}

void loop() {
    Serial.readBytesUntil('\r', rxBuff, sizeof(rxBuff) - 1);
    // Odczyt wartości i ich konwersja
    lcd.setCursor(0, 0); //W pierwszym wierszu jest wpisany tekst
    lcd.print(rxBuff);
    lcd.setCursor(0, 1);
    lcd.print("=");
    // Wykonanie obliczeń i wyświetlenie wyniku
}