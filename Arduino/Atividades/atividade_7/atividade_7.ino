int leds[8] = {1,2,3,4,5,6,7,8};

void setup() {
  for(int i = 0; i < 9; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int j = 0; j < 9; j++) {
    digitalWrite(leds[j], HIGH);
    delay(100);
  }
}
