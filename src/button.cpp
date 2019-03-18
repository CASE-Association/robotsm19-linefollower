#include <Arduino.h>
#include "button.h"

int button1State;             // the current reading from the input pin
int lastButton1State = HIGH;  // the previous reading from the input pin
int button2State;             
int lastButton2State = HIGH;

unsigned long lastDebounce1Time = 0;  // the last time the output pin was toggled
unsigned long lastDebounce2Time = 0; 
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


/*
 * @brief Function for setting up pushbuttons. Implemeted with internal pullup resistors.
 */
void buttonSetup(void){
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}

/*
 * @brief Function that reads button1. Implemeted with debounce.
 *        Has to be called consecutivly to know if the button was pressed or if it was noise.
 * @return (int) 0 means no press, positive means pressed.
 */
int readButton1(void){
  int reading = digitalRead(BUTTON1);

  // check to see if you just pressed the button
  // (i.e. the input went from HIGH to LOW),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButton1State) {
    // reset the debouncing timer
    lastDebounce1Time = millis();
  }

  if ((millis() - lastDebounce2Time) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    return 1;
  }
  
  lastButton1State = reading;
  return 0;
}

/*
 * @brief Function that reads button2. Implemeted with debounce. 
 *         Has to be called consecutivly to know if the button was pressed or if it was noise.
 * @return (int) 0 means no press, positive means pressed.
 */
int readButton2(void){
  int reading = digitalRead(BUTTON2);

  // check to see if you just pressed the button
  // (i.e. the input went from HIGH to LOW),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButton2State) {
    // reset the debouncing timer
    lastDebounce2Time = millis();
  }

  if ((millis() - lastDebounce2Time) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    return 1;
  }
  
  lastButton2State = reading;
  return 0;
}
