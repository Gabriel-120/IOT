void setup() {
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
}

void loop() {
  //0001
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);

  //0010
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(1000);
  //0011
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  //0100
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
  //0101
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  delay(1000);
  //0111
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(1000);
  //1000
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  //1001
  digitalWrite(13, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  delay(1000);
  //1010
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  //1011
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(1000);
  //1100
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(1000);
  //1101
  digitalWrite(13, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  delay(1000);
  //1110
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  //1111
  digitalWrite(13, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1000);
}