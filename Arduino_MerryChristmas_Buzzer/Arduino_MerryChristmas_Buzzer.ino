//www.elegoo.com
//2016.12.08

#include "C:\Users\ttjtv\Downloads\ELEGOO Super Starter Kit for UNO V1.0.2022.08.04\English\code\Lesson 7 Passive Buzzer\pitches\pitches.h"
 
// Notes of the melody (in the order they are to be played)
int melody[] = {
  NOTE_C5, NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, 
  NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, 
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5
};
// Durations of the notes: a 4 means a quarter note, 8 means an eighth note, etc.
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4,
  8, 8, 8, 8, 4, 4, 4,
  8, 8, 8, 8, 4, 4, 4,
  4, 8, 8, 8, 8, 4, 4,
  8, 8, 8, 8, 4, 4, 4
};

 
void setup() {
 
}
 
void loop() {  
  int melodyLength = sizeof(melody) / sizeof(int); // Calculate the number of notes

  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {

    // Calculate the note duration (tempo)
    int noteDuration = 1000 / noteDurations[thisNote];
    
    // Play the note
    tone(8, melody[thisNote], noteDuration); 

    // Calculate the pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Stop the tone
    noTone(8);
  }
   
  // restart after two seconds 
  delay(2000);
}
