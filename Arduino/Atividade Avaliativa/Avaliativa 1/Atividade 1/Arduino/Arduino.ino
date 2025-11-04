//Define os pinos para os LEDs
  const int led1pin = 7; // led Verde
  const int led2pin = 8; // led Vermelho
  
  #include <Wire.h>
#include <LiquidCrystal_I2C.h>


// --- CONFIGURAÇÕES ---
// Configura o LCD (endereço 0x27, 16 colunas, 2 linhas)
LiquidCrystal_I2C lcd(0x27, 16, 2);



// Variáveis para o controle de tempo
const long intervaloDeLeitura = 2000; // Ler a cada 2000 ms (2 segundos)
unsigned long tempoAnterior = 0;


void setup() {

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();

  // Inicializa o sensor DHT
  dht.begin();


  //Inicia a comunicação serial com a mesma velocidade do Python
  Serial.begin(9600);

  //Define os pinos LEDs como saída
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  
}

void loop() {
  unsigned long tempoAtual = millis();
 //Verifica se há algum dados disponivel para ser lidp na porta serial
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


void loop() {
// Pega o tempo atual do Arduino
unsigned long tempoAtual = millis();
// É hora de fazer uma nova leitura?
if (tempoAtual - tempoAnterior >= intervaloDeLeitura) {
// Se sim, marca o tempo atual como o da última leitura
