#include <IRremote.h>

#define ENABLE 5
#define DIRA 3
#define DIRB 4

const int receiver = 11; // Signal Pin of IR receiver

static const int increment = 50;
int fanValue = 255;
bool isOn = false;

IRrecv irrecv(receiver);
decode_results results;

void TogglePower() {
  isOn = !isOn;
  if (isOn) {
    analogWrite(ENABLE, fanValue); // resume at last speed
    Serial.print("Power ON, speed = ");
    Serial.println(fanValue);
  } else {
    analogWrite(ENABLE, 0);
    Serial.println("Power OFF");
  }
}

void PowerUp() {
  fanValue = constrain(fanValue + increment, 0, 255);
  if (isOn) analogWrite(ENABLE, fanValue);
  Serial.print("Speed up -> ");
  Serial.println(fanValue);
}

void PowerDown() {
  fanValue = constrain(fanValue - increment, 0, 255);
  if (isOn) analogWrite(ENABLE, fanValue);
  Serial.print("Speed down -> ");
  Serial.println(fanValue);
}

void translateIR() {
  switch (results.value) {
    case 0xFF45BA: TogglePower(); break;
    case 0xFF47B8: PowerUp();     break;
    case 0xFF46B9: PowerDown();   break;
    case 0xFFFFFFFF:
      Serial.println("REPEAT");
      break;
    default:
      Serial.print("Unrecognized code: 0x");
      Serial.println(results.value, HEX);
      break;
  }
}

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Direction fixed once, up front - matches the working L293D example
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);

  Serial.begin(9600);
  irrecv.enableIRIn(); // start the IR receiver
  Serial.println("Ready for IR input...");
}

void loop() {
  if (irrecv.decode(&results)) {
    translateIR();
    irrecv.resume(); // ready for the next signal
  }
}