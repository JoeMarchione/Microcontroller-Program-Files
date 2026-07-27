#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

IRrecv irrecv(receiver);
decode_results results;

void translateIR() {// takes action based on IR code received

  switch(results.value) {
  case 0xFF45BA: Serial.println("POWER"); break;
  case 0xFF47B8: Serial.println("FUNC/STOP"); break;
  case 0xFF46B9: Serial.println("VOL+"); break;
  case 0xFF44BB: Serial.println("FAST BACK");    break;
  case 0xFF40BF: Serial.println("PAUSE");    break;
  case 0xFF43BC: Serial.println("FAST FORWARD");   break;
  case 0xFF07F8: Serial.println("DOWN");    break;
  case 0xFF15EA: Serial.println("VOL-");    break;
  case 0xFF09F6: Serial.println("UP");    break;
  case 0xFF19E6: Serial.println("EQ");    break;
  case 0xFF0DF2: Serial.println("ST/REPT");    break;
  case 0xFF16E9: Serial.println("0");    break;
  case 0xFF0CF3: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF5EA1: Serial.println("3");    break;
  case 0xFF08F7: Serial.println("4");    break;
  case 0xFF1CE3: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF52AD: Serial.println("8");    break;
  case 0xFF4AB5: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;
  default: 
    Serial.print(" other button : ");
    Serial.println(results.value, HEX);
  }

  delay(500); // Do not get immediate repeat
}

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
}


void loop() {
  if (irrecv.decode(&results)) {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}
