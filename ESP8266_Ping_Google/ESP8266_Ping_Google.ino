#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include "secrets.h"

const char* host = "google.com";

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); //turn the LED off (LED_BUILTIN is active low)

  //connect to wifi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  //wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //if connection is established, print IP
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  //ping the host
  if (Ping.ping(host)) {
    Serial.println("");
    Serial.print("Ping to ");
    Serial.print(host);
    Serial.print(" successful. Time = ");
    Serial.print(Ping.averageTime());
    Serial.println(" ms");

    digitalWrite(LED_BUILTIN, LOW); //turn the LED on
    delay(100); //keep it on for 100 ms
    digitalWrite(LED_BUILTIN, HIGH); //turn the LED off

  } else {
    Serial.print("Ping to ");
    Serial.print(host);
    Serial.println(" failed.");
  }

  delay(3000);
}
