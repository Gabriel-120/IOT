#include <Servo.h>

// Criando os 4 servos
Servo servoX;       // Direita / Esquerda

// Posições iniciais
int posX = 90;
int pinoPotenciometro = A0;


void setup() {
  // Liga os servos aos pinos
  servoX.attach(9);

  // Posições iniciais
  servoX.write(posX);
}

void loop() {
  int leitura = analogRead(pinoPotenciometro);
  int brilho = map(leitura, 0, 1023, 0, 255);

  // Movimento eixo X (direita/esquerda)
  if (brilho > 127) {
    posX = constrain(posX + 1, 0, 180);
    servoX.write(posX);
    delay(15);
  }
  if (brilho < 127) {
    posX = constrain(posX - 1, 0, 180);
    servoX.write(posX);
    delay(15);
  }

}

