const int pinoSensorMovimento = 2;

const int pinosLeds[] = {3, 4, 5, 6, 7};
const int numeroTotalLeds = 5;

int contadorPessoas = 0;

int estadoAnteriorSensor = LOW;

void setup() {
  pinMode(pinoSensorMovimento, INPUT);

  for (int i = 0; i < numeroTotalLeds; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("Detector de movimento ativado!");
}

void loop() {
  int estadoAtualSensor = digitalRead(pinoSensorMovimento);

  if (estadoAtualSensor == HIGH && estadoAnteriorSensor == LOW) {
    if (contadorPessoas < numeroTotalLeds) {
      contadorPessoas++;
    }

    digitalWrite(pinosLeds[contadorPessoas - 1], HIGH);

    Serial.print("Movimento detectado! Pessoas: ");
    Serial.println(contadorPessoas);
  }
  
  if (estadoAtualSensor == LOW && estadoAnteriorSensor == HIGH) {

    for (int i = 0; i < numeroTotalLeds; i++) {
      digitalWrite(pinosLeds[i], LOW);
    }

    contadorPessoas = 0;
    Serial.println("Movimento cessou. Contador zerado.");
  }

  estadoAnteriorSensor = estadoAtualSensor;
  delay(50);
}