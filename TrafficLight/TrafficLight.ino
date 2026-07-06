int ledONG = 11; //attach an LED to pin 11 and GND
int ledRED = 10;
int ledGRN = 12;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize digital pin 11 as an output.
  pinMode(ledONG, OUTPUT);
  pinMode(ledRED, OUTPUT);
  pinMode(ledGRN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  // delay(1000);                       // wait for a 500 miliseconds
  // digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  // delay(0);                       // wait for a 500 miliseconds

  digitalWrite(ledONG, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(5000);               // wait for a 750 miliseconds
  digitalWrite(ledONG, LOW);   // turn the LED off by making the voltage LOW
  delay(0);               // wait for 750 miliseconds

  digitalWrite(ledRED, HIGH);
  delay(5000);
  digitalWrite(ledRED, LOW);
  delay(0);

  digitalWrite(ledGRN, HIGH);
  delay(5000);
  digitalWrite(ledGRN, LOW);
  delay(0);
}