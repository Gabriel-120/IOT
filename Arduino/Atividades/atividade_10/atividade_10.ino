
String frase = "Hello";

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  for (int i = 0; i < frase.length(); i++) {
    char g = toupper(frase.charAt(i));

    if (g == ' ') {        
      delay(7 * 200);
      continue;
    }

    const char* codigo = morseFor(g);
    if (codigo == nullptr) continue;

    for (int j = 0; codigo[j] != '\0'; j++) {
      if (codigo[j] == '.') ponto();
      if (codigo[j] == '-') trao();
    }
    delay(2 * 200);
  }

  delay(5000);
}

const char* morseFor(char g) {
  switch (g) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    default:  return nullptr;
  }
}

void ponto() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}

void trao() {
  digitalWrite(13, HIGH);
  delay(3 * 200);
  digitalWrite(13, LOW);
  delay(200);
}