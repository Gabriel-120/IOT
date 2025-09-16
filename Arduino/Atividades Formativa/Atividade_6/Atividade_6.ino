// Medidor de Brilho Ambiente com LDR
//esse código mostra a variação de luz no Serial Monitor

int pinoLDR = A0;   // Entrada analógica
int valorLuz = 0;   // Variável para armazenar o valor lido

void setup() {
  Serial.begin(9600);  // Inicia comunicação serial
}

void loop() {
  valorLuz = analogRead(pinoLDR);  // Lê valor do LDR (0 a 1023)
  
  Serial.print("Valor de luminosidade: ");
  Serial.println(valorLuz);        // Mostra no Monitor Serial

  delay(500);  // Meio segundo entre leituras
}
