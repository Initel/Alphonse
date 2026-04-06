#define MOSFET_PIN 5
#define HALL_PIN 20

int brilho = 0;

void setup() {
  Serial.begin(115200);

  // Configura PWM no MOSFET
  ledcAttach(MOSFET_PIN, 5000, 8);

  // Configura sensor Hall (A3144 com pull-up externo)
  pinMode(HALL_PIN, INPUT);

  Serial.println("Sistema iniciado");
}

void loop() {

  int estado = digitalRead(HALL_PIN);

  // DEBUG (opcional)
  if (estado == LOW) {
    Serial.println("IMÃ DETECTADO");
  } else {
    Serial.println("SEM IMÃ");
  }

  // 🟢 Ímã presente → FADE IN
  if (estado == LOW) {
    if (brilho < 255) {
      brilho += 10;
      if (brilho > 255) brilho = 255;
    }
    
  } 
  // 🔴 Ímã ausente → FADE OUT
  else {
    if (brilho > 0) {
      brilho -= 5;
      if (brilho < 0) brilho = 0;
    }
  }

  // Aplica brilho no LED (via MOSFET)
  ledcWrite(MOSFET_PIN, brilho);

  delay(35);
}