int leds[8] = {1, 2, 3, 4, 5, 6, 7, 8};
void setup() {
for(int i = 0; i < 9; i++){
  pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  for(int g = 0; g < 9; g++){
    digitalWrite(leds[g], HIGH);
    delay(100);
    digitalWrite(leds[g], LOW);
    delay(100);
  }
  for(int g = 8; g > 0; g--){
    digitalWrite(leds[g], HIGH);
    delay(100);
    digitalWrite(leds[g], LOW);
    delay(100);
  }
}