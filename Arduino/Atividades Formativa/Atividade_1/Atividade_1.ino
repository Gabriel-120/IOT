
//Biblioteca do DTH
#include "DHT.h"
//armazena o valor flutuante de temperatura
float temperatura;
//porta usada e o tipo de sensor
DHT dht(3, DHT11);
int pinled1 = 13;
int pinled2 = 12;
int pinled3 = 11;

void setup() {
  Serial.begin(9600);  // inicializando o monitor serial
  dht.begin();         // Inicializando o sensor
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
}

void loop() {
  delay(2000);                          // Aguarda dois segundos entre as leituras
  temperatura = dht.readTemperature();  //Lê o valor da temperatura em C°

  //Verificando se existe erro na leitura da temperatura
  if (isnan(temperatura)) { Serial.println("ERRO NO SENSOR!"); }
  //Se tudo funcionar envia a temperatura para a serial
  else {
    Serial.println(temperatura); /*em C°*/
  }

  if (temperatura <= 24 && temperatura >= 15) {
    digitalWrite(pinled1, HIGH); 
    digitalWrite(pinled2, LOW); 
    digitalWrite(pinled3, LOW); 
  } else if (temperatura <= 29 && temperatura > 24) {
    digitalWrite(pinled2, HIGH);
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled3, LOW);
  } else {
    digitalWrite(pinled3, HIGH);
    digitalWrite(pinled1, LOW);
    digitalWrite(pinled2, LOW);
  }
}

