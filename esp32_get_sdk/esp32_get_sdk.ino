#include "esp_wifi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("ESP32 SDK Version: ");
  Serial.println(ESP.getSdkVersion());
}

void loop() {
  // put your main code here, to run repeatedly:

}
