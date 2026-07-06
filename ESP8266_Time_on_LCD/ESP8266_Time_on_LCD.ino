#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <time.h>

const char* ssid = ""; //creds
const char* password = "";

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
  timeClient.setTimeOffset(-4 * 60 * 60); // offset time to match eastern daylight time

  Serial.println("NTP client started");
  lcd.clear();
  lcd.print("NTP client started");
  delay(1000);
}

void loop() {
  timeClient.update();

  // print to serial
  Serial.print("The current time is: ");
  Serial.println(timeClient.getFormattedTime());

  //print time
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time (Eastern):");
  lcd.setCursor(0, 1);
  lcd.print(timeClient.getFormattedTime());

  delay(1000);
}
