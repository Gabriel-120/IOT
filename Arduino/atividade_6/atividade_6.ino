const int botao = 12;
int botaostatus = 0;
int Estado = HIGH;
bool estado = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  botaostatus = digitalRead(botao);

  if (botaostatus == LOW && Estado == HIGH) {
    estado = !estado;
    digitalWrite(13, estado);
    delay(200);
  }

  Estado = botaostatus;
}