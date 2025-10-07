// --- BIBLIOTECAS ---
#include <Wire.h>
#include <LiquidCrystal.h>
#include "DHT.h" 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int DHT_PIN = 9; 

const int DHT_TYPE = DHT11; 
DHT dht(DHT_PIN, DHT_TYPE);

const long intervaloDeLeitura = 2000; 

unsigned long tempoAnterior = 0;
void setup() {

 lcd.begin(16, 2);
  lcd.clear();

dht.begin();

lcd.setCursor(0, 0);
lcd.print("Estacao Climat.");
lcd.setCursor(0, 1);
lcd.print("Iniciando...");
delay(1500); 
}
void loop() {

unsigned long tempoAtual = millis();

if (tempoAtual - tempoAnterior >= intervaloDeLeitura) {


tempoAnterior = tempoAtual;

float temperatura = dht.readTemperature();
float umidade = dht.readHumidity();

if (isnan(temperatura) || isnan(umidade)) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Falha na leitura");
lcd.setCursor(0, 1);
lcd.print("do sensor!");
return; 
}

lcd.clear();

lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperatura, 1); 
lcd.print((char)223); 
lcd.print("C");

lcd.setCursor(0, 1);
lcd.print("Umid: ");
lcd.print(umidade, 1); 
lcd.print(" %");
}
}