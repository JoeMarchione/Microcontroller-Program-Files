//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define buz 8
#define led 9
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(buz, OUTPUT);
   pinMode(led, OUTPUT);
   digitalWrite(buz, LOW);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(250);

   while (a <= 15) {
    digitalWrite(buz, HIGH);
    digitalWrite(led, HIGH);
    break;
   }

   while (a >= 15) {
    digitalWrite(buz, LOW);
    digitalWrite(led, LOW);
    break;
   }
}
