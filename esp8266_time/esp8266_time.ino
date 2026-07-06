#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <time.h>
#include "secrets.h"

// define NTP client to get the time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void ConnectToNetwork() {
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS); //connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  delay(1000);

  timeClient.begin(); // start the time client
  timeClient.setTimeOffset(-4 * 60 * 60); // offset time to match eastern daylight time

  Serial.println("NTP client started");
}

void GetTime() {
  timeClient.update();
  // print to serial
  Serial.print("The current time is: ");
  Serial.println(timeClient.getFormattedTime());
}

void setup() {
  Serial.begin(115200);
  ConnectToNetwork();
  delay(1000);
}

void loop() {
  GetTime();
  delay(1000);
}
