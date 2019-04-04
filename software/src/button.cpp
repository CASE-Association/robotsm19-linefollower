#include "button.h"
#include <Arduino.h>

// Buttons are configured with PULLUP resistors => 5V default, 0V when pressed.
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;  // the debounce time; increase if the output flickers

/*
 * @brief Function for setting up pushbuttons. Implemeted with internal pullup resistors.
 */
void buttonSetup(void) {
    pinMode(BUTTON, INPUT_PULLUP);
}

/*
 * @brief Function that reads the button. Implemeted with debounce.
 *        Has to be called consecutivly to know if the button was pressed or if it was noise.
 * @return (int) 0 means no press, positive means pressed.
 */
int readButtonRight(void) {
    int buttonRightState = digitalRead(BUTTON);
    int returnVal = 0;
    // check to see if you just pressed the button
    // (i.e. the input went from HIGH to LOW),  and you've waited
    // long enough since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (buttonRightState != lastButtonState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        if (!buttonRightState) {
            // Pullup to 5V => Normally 5V, Pressed 0V
            returnVal = 1;
        }
    }

    lastButtonState = buttonRightState;
    return returnVal;
}

