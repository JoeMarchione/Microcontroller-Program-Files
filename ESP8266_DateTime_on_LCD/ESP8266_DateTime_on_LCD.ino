#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <time.h>
#include "secrets.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

// define NTP client to get the time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//set LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SDA_PIN 4 // GPIO 4 (D2)
#define SCL_PIN 5 // GPIO 5 (D1)

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN); // initialize comms w/ I2C display

  // initialize lcd
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Connecting to");
  lcd.setCursor(0,1);
  lcd.print(ssid);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); //connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    lcd.print(".");
  }

  Serial.println("WiFi connected");
  lcd.clear();
  lcd.print("WiFi connected");
  delay(1000);

  timeClient.begin(); // start the time client

  Serial.println("NTP client started");
  lcd.clear();
  lcd.print("NTP client started");
  delay(1000);
}

void loop() {
  timeClient.update();

  // get epoch time and covert it into a tm struct
  time_t rawTime = timeClient.getEpochTime();
  struct tm* timeInfo = localtime(&rawTime);

  // determine if daylight savings are in effect
  int dstOffset = 0;
  if ((timeInfo->tm_mon > 2 && timeInfo->tm_mon < 10) || 
      (timeInfo->tm_mon == 2 && timeInfo->tm_mday - timeInfo->tm_wday >= 7) ||
      (timeInfo->tm_mon == 10 && timeInfo->tm_mday - timeInfo->tm_wday < 7)) {
    dstOffset = 3600; // Add one hour for DST (EDT)
  }

  // apply the offset
  rawTime += (dstOffset - 5 * 3600);
  timeInfo = localtime(&rawTime);

  // format date and time
  char dateBuffer[11]; // buffer for date string
  char timeBuffer[9]; // buffer for time string
  strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", timeInfo);
  strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", timeInfo);

  // Print the date and time on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.print(dateBuffer);
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(timeBuffer);

  // print to serial monitor for debugging
  Serial.print("Date: ");
  Serial.println(dateBuffer);
  Serial.print("Time: ");
  Serial.println(timeBuffer);
  Serial.println("");

  delay(1000);
}
