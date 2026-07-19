#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include <LiquidCrystal.h>

//     LCD Pin:   RS E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temp ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity ");
}

static bool measure_environment(float* temperature, float* humidity) {
  static unsigned long measurement_timestamp = millis();

  /* Measure once every half second. */
  if(millis() - measurement_timestamp > 2000ul)
  {
    if(dht_sensor.measure(temperature, humidity) == true)
    {
      measurement_timestamp = millis();
      return(true);
    }
  }
  return(false);
}

void PrintTempAndHumidity() {
  float temperature;
  float humidity;

  if (measure_environment(&temperature, &humidity) == true) {
    float tempF = temperature * (9.0/5.0) + 32.0;

    lcd.setCursor(6, 0);
    lcd.print(tempF);
    lcd.print(" F");

    lcd.setCursor(10, 1);
    lcd.print(humidity);
    lcd.print("%");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  PrintTempAndHumidity();
}
