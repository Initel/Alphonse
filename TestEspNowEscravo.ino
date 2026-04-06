/* 
  Endereços MAC

  Mestre
  - 10:00:3B:CD:5A:94

  Escravo
  - 10:00:3B:CD:78:30

*/

#include <WiFi.h>
#include <esp_now.h>

#define Led 8  // GPIO do LED onboard (geralmente 8 no C3)

bool ledstatus = false;
char MSN[20];

// Callback de recebimento
void receive(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  memcpy(MSN, incomingData, len);
  MSN[len] = '\0'; // final da string

  Serial.print("Recebido: ");
  Serial.println(MSN);

  if (strcmp(MSN, "OF") == 0) {
    ledstatus = !ledstatus;

    // LED invertido no ESP32-C3
    digitalWrite(Led, ledstatus ? LOW : HIGH);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(Led, OUTPUT);
  digitalWrite(Led, HIGH); // começa desligado (invertido)

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(receive);

  Serial.println("Escravo pronto.");
}

void loop() {
  // Nada aqui
} 
