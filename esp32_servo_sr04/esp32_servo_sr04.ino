#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Servo.h"

const int trigPin = 5;
const int echoPin = 18;

// const int SDA_PIN = 21;
// const int SCL_PIN = 22;

const int servoPin = 13;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

//set LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo1;

void sonar() {
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

  // brint outbut
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  Serial.println("");

  // lcd.setCursor(0, 0);
  // lcd.print("Dist (cm): ");
  // lcd.print(distanceCm);
  // lcd.setCursor(0, 1);
  // lcd.print("Dist (in): ");
  // lcd.print(distanceInch);
}

void moveServo() {
  for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees);
    sonar();
    //Serial.println(posDegrees);
    delay(10);
  }

  for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    sonar();
    //Serial.println(posDegrees);
    delay(10);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Wire.begin(SDA_PIN, SCL_PIN);
  // lcd.begin(16, 2);
  // lcd.backlight();

  servo1.attach(servoPin);
}

void loop() {
  moveServo();

  delay(500);
}
