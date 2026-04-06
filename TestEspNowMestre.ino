/* 
  Endereços MAC

  Mestre
  - 10:00:3B:CD:5A:94

  Escravo
  - 10:00:3B:CD:78:30

*/

#include <WiFi.h>
#include <esp_now.h>

// MAC do escravo
uint8_t slave[] = {0x10, 0x00, 0x3B, 0xCD, 0x78, 0x30};

char msn[20] = "";
String recebido = "";

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Erro ao iniciar ESP-NOW");
    return;
  }

  // Configurar peer
  esp_now_peer_info_t slaveInfo = {};
  memcpy(slaveInfo.peer_addr, slave, 6);
  slaveInfo.channel = 0;
  slaveInfo.encrypt = false;

  if (esp_now_add_peer(&slaveInfo) != ESP_OK) {
    Serial.println("Erro ao adicionar peer");
    return;
  }

  Serial.println("Mestre pronto. Digite OF e pressione Enter.");
}

void loop() {
  if (Serial.available()) {
    recebido = Serial.readString();
    recebido.trim(); // remove \n e espaços

    Serial.print("Texto Recebido: ");
    Serial.println(recebido);
  }

  if (recebido == "OF") {
    strcpy(msn, "OF");

    esp_err_t result = esp_now_send(slave, (uint8_t *)msn, strlen(msn));

    if (result == ESP_OK) {
      Serial.println("Enviado com sucesso");
    } else {
      Serial.println("Erro no envio");
    }

    recebido = ""; // limpa para não reenviar
  }
}