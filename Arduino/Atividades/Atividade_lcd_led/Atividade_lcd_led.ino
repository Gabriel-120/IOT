#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  lcd.begin(16, 2);
  lcd.clear();
  digitalWrite(6, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Led verde");
  lcd.setCursor(0, 1);
  lcd.print("Esta ativado");
  delay(5000);
  lcd.clear();
  digitalWrite(6, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Led verde");
  lcd.setCursor(0, 1);
  lcd.print("Esta Desativado");
  delay(5000);
  lcd.clear();
  digitalWrite(7, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Led vermelho");
  lcd.setCursor(0, 1);
  lcd.print("Esta ativado");
  delay(5000);
  lcd.clear();
  digitalWrite(7, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Led vermelho");
  lcd.setCursor(0, 1);
  lcd.print("Esta Desativado");
  delay(5000);
}
