
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  setColor(0, 0, 0);
}

void loop() {
  setColor(255, 0, 0); delay(500); 
  setColor(0, 255, 0); delay(500); 
  setColor(0, 0, 255); delay(500); 
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
}