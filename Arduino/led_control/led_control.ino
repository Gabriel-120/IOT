// Definição dos pinos para os LEDs
const int LED_1 = 13;  // LED Verde no pino 13 (LED_BUILTIN)
const int LED_2 = 12;  // LED Vermelho no pino 12

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera a porta serial conectar. Necessário para USB nativa
  }
  
  // Configura os pinos dos LEDs como saída
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  
  // Inicializa os LEDs desligados
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  
  // Teste inicial dos LEDs
  testLEDs();
  
  // Envia mensagem de ready
  Serial.println("Arduino ready!");
}

void testLEDs() {
  // Pisca cada LED uma vez para teste
  digitalWrite(LED_1, HIGH);
  delay(500);
  digitalWrite(LED_1, LOW);
  delay(500);
  digitalWrite(LED_2, HIGH);
  delay(500);
  digitalWrite(LED_2, LOW);
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    // Lê o comando recebido
    char command = Serial.read();
    
    // Processa o comando
    switch (command) {
      case 'A':  // Ligar LED 1
        digitalWrite(LED_1, HIGH);
        Serial.println("LED 1 ON");
        break;
      case 'a':  // Desligar LED 1
        digitalWrite(LED_1, LOW);
        Serial.println("LED 1 OFF");
        break;
      case 'B':  // Ligar LED 2
        digitalWrite(LED_2, HIGH);
        Serial.println("LED 2 ON");
        break;
      case 'b':  // Desligar LED 2
        digitalWrite(LED_2, LOW);
        Serial.println("LED 2 OFF");
        break;
      case 'T':  // Comando de teste
        testLEDs();
        Serial.println("TEST OK");
        break;
      default:
        Serial.println("Invalid command");
        break;
    }
  }
}