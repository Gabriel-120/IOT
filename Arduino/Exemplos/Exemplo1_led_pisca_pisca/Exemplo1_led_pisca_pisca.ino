const int led_amarelo = 9;
const int led_verde = 10;
const int led_vermelho = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
  delay(5000);
  
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_vermelho, LOW);
  delay(2000);
  
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, HIGH);
  delay(5000);

}
