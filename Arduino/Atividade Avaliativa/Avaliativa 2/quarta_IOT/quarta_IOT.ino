#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

#define DHTPIN 34
#define DHTTYPE DHT11
#define LDR_PIN 35

#define LED_VERDE 27
#define LED_AMARELO 14
#define LED_VERMELHO 12
#define BUZZER 13


const char* ssid = "Motog52";       
const char* password = "Gabriel2025";  

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

bool leituraAtiva = true;
bool incendioAtivo = false; 


IPAddress local_IP;
IPAddress gateway;
IPAddress subnet(255, 255, 255, 0);

void configurarIP() {
  WiFi.begin(ssid, password);
  Serial.println("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  IPAddress ip = WiFi.localIP();
  gateway = WiFi.gatewayIP();
  local_IP = IPAddress(ip[0], ip[1], ip[2], 250);

  WiFi.disconnect(true);
  delay(1000);

  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("Falha ao configurar IP estático!");
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado!");
  Serial.print("Acesse o site em: http://");
  Serial.println(WiFi.localIP());
}


String statusAmbiente(float temp, int luz) {
  String status;

  if (temp <= 30) {
    status = "<span style='color: #00ff88;'>Ambiente normal</span>";
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
    incendioAtivo = false;
  }
  else if (temp > 30 && luz < 80) {
    status = "<span style='color: #FFD700;'>Risco de incêndio! Fique alerta!</span>";
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);

    // 3 bipes de 2 segundos
    for (int i = 0; i < 3; i++) {
      tone(BUZZER, 1000);
      delay(2000);
      noTone(BUZZER);
      delay(500);
    }
    incendioAtivo = false;
  }
  else if (temp > 30 && luz >= 80) {
    status = "<span style='color: #FF4444;'>INCÊNDIO DETECTADO! CHAME OS BOMBEIROS!</span>";
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);

    tone(BUZZER, 1200); // buzzer contínuo
    incendioAtivo = true;
  }

  return status;
}


String gerarPaginaHTML(float temp, float umid, int luz) {
  String status = statusAmbiente(temp, luz);

  String html = R"====(
  <html>
  <head>
    <meta http-equiv="refresh" content="3">
    <title>Monitor de Incêndio - ESP32</title>
    <style>
      body {
        font-family: Arial;
        background-color: #1b1b1b;
        color: white;
        text-align: center;
      }
      .card {
        background: #222;
        border-radius: 15px;
        padding: 20px;
        margin: 30px auto;
        width: 320px;
        box-shadow: 0 0 10px #555;
      }
      button {
        background: #12A4DB;
        border: none;
        padding: 10px 20px;
        color: white;
        border-radius: 10px;
        font-size: 16px;
        cursor: pointer;
      }
      button:hover { background: #0e8bbf; }
    </style>
  </head>
  <body>
    <h2>Monitor de Incêndio Inteligente</h2>
    <div class='card'>
  )====";

  html += "<p><b>Temperatura:</b> " + String(temp, 1) + " °C</p>";
  html += "<p><b>Umidade:</b> " + String(umid, 1) + " %</p>";
  html += "<p><b>Iluminação:</b> " + String(luz) + " %</p>";
  html += "<hr>";
  html += "<h3>Status do Ambiente:</h3>";
  html += "<p>" + status + "</p>";
  html += "<form action='/toggle' method='POST'><button>Alternar Leitura</button></form>";
  html += "<p>Status da leitura: <b>" + String(leituraAtiva ? "Ativa " : "Pausada ") + "</b></p>";
  html += "</div></body></html>";
  return html;
}

// ===================== ROTAS =====================

void handleRoot() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int leituraLDR = analogRead(LDR_PIN);
  int luminosidade = map(leituraLDR, 0, 4095, 100, 0);

  if (isnan(temperatura) || isnan(umidade)) {
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER, 800, 500);
    temperatura = 0;
    umidade = 0;
  }

  server.send(200, "text/html", gerarPaginaHTML(temperatura, umidade, luminosidade));
}

void handleToggle() {
  leituraAtiva = !leituraAtiva;
  if (!leituraAtiva) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}


void setup() {
  Serial.begin(115200);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  noTone(BUZZER);

  tone(BUZZER, 800, 200); // sinal inicial

  dht.begin();
  configurarIP();

  server.on("/", handleRoot);
  server.on("/toggle", HTTP_POST, handleToggle);
  server.begin();

  Serial.println(" Servidor iniciado!");
}


void loop() {
  server.handleClient();

  if (leituraAtiva) {
    delay(2000);
  } else {
    delay(500);
  }

  if (incendioAtivo) {
    float temperatura = dht.readTemperature();
    if (temperatura <= 30) {
      noTone(BUZZER);
      incendioAtivo = false;
    }
  }
}
