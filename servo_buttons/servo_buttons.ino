//www.elegoo.com
//2016.12.08
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#define leftbtn 2
#define rightbtn 5

bool leftbtnActive = false;
bool rightbtnActive = false;

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {

  // Move servo towards 180 degrees while left button is held down
  while (digitalRead(leftbtn) == LOW) {
    if (pos < 180) {
      pos++;
      myservo.write(pos);
      delay(5); // Adjust this delay if necessary
    }
  }

  // Move servo towards 0 degrees while right button is held down
  while (digitalRead(rightbtn) == LOW) {
    if (pos > 0) {
      pos--;
      myservo.write(pos);
      delay(5); // Adjust this delay if necessary
    }
  }
}

