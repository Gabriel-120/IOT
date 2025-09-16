#define trigPin 9
#define echoPin 10
#define buzzerPin 13

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);
}

void loop() {
// Envia pulso ultrassônico
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH); // Lê duração do eco
float distance = duration * 0.034 / 2; // Converte em distância (cm)

// Verifica se há presença (até 20 cm)
if (distance <= 20) {
digitalWrite(buzzerPin, HIGH); // Acende o LED
} else {
digitalWrite(buzzerPin, LOW); // Apaga o LED
}

delay(200); // Pequena pausa para estabilidade
}