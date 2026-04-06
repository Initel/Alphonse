#include <WiFi.h>
#include <esp_now.h>

uint8_t slave[] = 
char msn[20] = "";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  delay(200);
  Serial.print("Endereço Mac: ");
  Serial.println(WiFi.macAddress());

  while(1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
