#include "WiFi.h"
#include "secrets.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

void initWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // wait for connection
  int retries = 0;
  const int maxRetries = 30;
  while (WiFi.status() != WL_CONNECTED && retries < maxRetries) {
    delay(1000);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    // print the IP address once connected
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("Failed to connect to WiFi.");
    Serial.print("WiFi.status(): ");
    Serial.println(WiFi.status());
  }
}

void setup() {
  Serial.begin(115200);

  initWiFi();
}

void loop() {

}
