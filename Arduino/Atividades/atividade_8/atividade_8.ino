const int potPin = A0;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int leds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < leds; i++) pinMode(ledPins[i], OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int leitura = analogRead(potPin);                 // 0..1023
  int nivel = map(leitura, 0, 1023, 0, leds);   // 0..8

  for (int i = 0; i < leds; i++) {
    digitalWrite(ledPins[i], i < nivel ? HIGH : LOW);
  }
}