#define buzzer 12
#define ballSwitch 2
//#define debounceDelay 500 //ms for debounce

// unsigned long lastDebounceTime = 0;
// int lastSwitchState;
// int switchState;

void setup() {
  // put your setup code here, to run once:
  pinMode(ballSwitch, INPUT_PULLUP);  // Initialize ball switch as an input with internal pull-up
  pinMode(buzzer, OUTPUT);            // Initialize buzzer as an output
  digitalWrite(buzzer, LOW);          // Ensure the buzzer starts off

  // switchState = digitalRead(ballSwitch); // Initialize switchState with the current state of ballSwitch
  // lastSwitchState = switchState;
}

void loop() {
  //put your main code here, to run repeatedly:
  if (digitalRead(ballSwitch) == HIGH)
  {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);        // Turn off the buzzer when the ball switch is not tilted
  }

//   int reading = digitalRead(ballSwitch);

//   //check if switched state has been changed
//   if (reading != lastSwitchState)
//   {
//     lastDebounceTime = millis(); //reset the timer
//   }

//   if ((millis() - lastDebounceTime) > debounceDelay) 
//   {
//     if (reading != switchState) 
//     {
//       switchState = reading;
//       digitalWrite(buzzer, switchState == HIGH ? HIGH : LOW);
//     }
//   }

//   lastSwitchState = reading;
}
