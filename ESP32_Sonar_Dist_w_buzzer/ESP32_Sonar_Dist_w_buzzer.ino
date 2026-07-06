#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 5;
const int echoPin = 18;

const int SDA_PIN = 21;
const int SCL_PIN = 22;

const int buzz = 23;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

//set LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);

  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  //clears the trigpin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //sets the trigpin to high for 10uS
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //reads the echo pin and stores the wave travel time in the 'duration' variable
  duration = pulseIn(echoPin, HIGH);
  //calculate distance 
  distanceCm = duration * SOUND_SPEED/2;
  //convert cm to inches
  distanceInch = distanceCm * CM_TO_INCH;

  if (distanceCm < 20) {
    digitalWrite(buzz, HIGH);
  } else {
    digitalWrite(buzz, LOW);
  }

  // brint outbut
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  Serial.println("");

  lcd.setCursor(0, 0);
  lcd.print("Dist (cm): ");
  lcd.print(distanceCm);
  lcd.setCursor(0, 1);
  lcd.print("Dist (in): ");
  lcd.print(distanceInch);

  delay(1000);
}
