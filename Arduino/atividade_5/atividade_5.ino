int pinoPotenciometro = A0;
int pinoLED = 9;

void setup() {
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  int leitura = analogRead(pinoPotenciometro);
  int brilho = map(leitura, 0, 1023, 0, 255);
  analogWrite(pinoLED, brilho);
  delay(10);
}
