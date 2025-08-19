void setup() {
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  delay(2000);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
 digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(7, LOW);
  delay(2000);
}