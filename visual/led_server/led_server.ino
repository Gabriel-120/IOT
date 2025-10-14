// Define os pinos dos LEDs
const int led1Pin = 7; // LED Verde
const int led2Pin = 8; // LED Vermelho

void setup() {
  // Inicia a comunicação serial com a mesma velocidade do Python (9600)
  Serial.begin(9600);

  // Define os pinos dos LEDs como saída
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  // Verifica se há dado disponível na porta serial
  if (Serial.available() > 0) {
    // Lê o caractere recebido
    char command = Serial.read();

    // Executa a ação com base no comando
    switch (command) {
      case 'A':
        digitalWrite(led1Pin, HIGH); // Liga o LED 1
        break;
      case 'a':
        digitalWrite(led1Pin, LOW);  // Desliga o LED 1
        break;
      case 'B':
        digitalWrite(led2Pin, HIGH); // Liga o LED 2
        break;
      case 'b':
        digitalWrite(led2Pin, LOW);  // Desliga o LED 2
        break;
      // Adicione mais comandos se necessário
      default:
        break;
    }
  }
}
