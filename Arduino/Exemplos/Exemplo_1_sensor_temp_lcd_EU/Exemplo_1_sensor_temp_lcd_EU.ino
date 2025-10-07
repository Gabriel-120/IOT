//Biblioteca do DTH
#include "DHT.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temperatura;
DHT dht(9, DHT11);

void setup() {

  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Temp:        C");
 

}


void loop() {

delay(2000);
lcd.setCursor(7,0);
temperatura = dht.readTemperature();
if (isnan(temperatura)) { lcd.print("ERRO NO SENSOR!");}
else {lcd.print(temperatura); }

delay(500);
}
