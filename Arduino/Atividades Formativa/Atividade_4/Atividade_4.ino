int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;
int ledBranco = 11;

int botaoPedestre = 7;

bool pedestreSolicitou = false;


void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botaoPedestre, INPUT);
  pinMode(ledBranco, OUTPUT);
}

// Configuração da porta 13 - Luz Vermelha
void loop() {
  // verifica se o botao foi pressionado
  if (digitalRead(botaoPedestre) == HIGH) {
    pedestreSolicitou = true;
  }

  //Semafaro - ciclo padrao
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  delay(5000);


  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(2000);

  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(5000);
  
   
  if  (pedestreSolicitou) {
      // Mantem vermelho por mais tempo para pedestre
    delay(7000); // tempo extra para passagem segura
    pedestreSolicitou = false;  // Reseta o pedido
  }
}
