//Biblioteca do DTH
#include "DHT.h"
//armazena o valor de temperatura

  float temperatura;
//porta usada e o tipo de sensor

  const int led1pin = 7; // led Verde
  const int led2pin = 8; // led Vermelho

  DHT dht(3, DHT11);


void setup() {
  Serial.begin(9600);// inicializando o monitor serial
  dht.begin();// Inicializando o sensor
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);

}


  void loop() {
  delay(2000);// Aguarda dois segundos entre as leituras
  temperatura = dht.readTemperature();//Lê o valor da temperatura em C°
//Verificando se existe erro na leitura da temperatura

  if (isnan(temperatura)) { Serial.println("ERRO NO SENSOR!");}
//Se tudo funcionar envia a temperatura para a serial
  else {Serial.println(temperatura); /*em C°*/}

  if (Serial.available() > 0) {
  //Lê o caractere recebido
  char command = Serial.read();

  //Executa a ação baseada no comando
  switch (command) {
    case 'A':
    digitalWrite(led1pin, HIGH); //Liga o LED 1
    break;
    case 'a':
    digitalWrite(led1pin, LOW); //Desliga o LED 1
    break;
    case 'B':
    digitalWrite(led2pin, HIGH); //Liga o LED 2
    break;
    case 'b':
    digitalWrite(led2pin, LOW); //Desliga o LED 2
    break;
   }
  }
}