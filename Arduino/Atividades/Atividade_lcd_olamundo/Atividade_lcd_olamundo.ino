#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ola, mundo!");
  lcd.setCursor(0, 1);
  lcd.print("Oi Bruno!");
}

void loop() {
  // O loop pode ficar vazio, pois a mensagem é estática.
}
