#include "button.h"
#include <Arduino.h>
#include "led.h"

// Buttons are configured with PULLUP resistors => 5V default, 0V when pressed.

int buttonRightState;             // the current reading from the input pin
int lastButtonRightState = HIGH;  // the previous reading from the input pin
int buttonLeftState;
int lastButtonLeftState = HIGH;

unsigned long lastDebounceRightTime = 0;  // the last time the output pin was toggled
unsigned long lastDebounceLeftTime = 0;
unsigned long debounceDelay = 50;  // the debounce time; increase if the output flickers

/*
 * @brief Function for setting up pushbuttons. Implemeted with internal pullup resistors.
 */
void buttonSetup(void) {
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
}

/*
 * @brief Function that reads button1. Implemeted with debounce.
 *        Has to be called consecutivly to know if the button was pressed or if it was noise.
 * @return (int) 0 means no press, positive means pressed.
 */
int readButtonRight(void) {
    int buttonRightState = digitalRead(BUTTON_RIGHT);
    int returnVal = 0;
    // check to see if you just pressed the button
    // (i.e. the input went from HIGH to LOW),  and you've waited
    // long enough since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (buttonRightState != lastButtonRightState) {
        // reset the debouncing timer
        lastDebounceRightTime = millis();
    }

    if ((millis() - lastDebounceRightTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        if (!buttonRightState) {
            // Pullup to 5V => Normally 5V, Pressed 0V
            returnVal = 1;
        }
    }

    lastButtonRightState = buttonRightState;
    return returnVal;
}

/*
 * @brief Function that reads button2. Implemeted with debounce. 
 *         Has to be called consecutivly to know if the button was pressed or if it was noise.
 * @return (int) 0 means no press, positive means pressed.
 */
int readButtonLeft(void) {
    int buttonLeftState = digitalRead(BUTTON_LEFT);
    int returnVal = 0;
    // check to see if you just pressed the button
    // (i.e. the input went from HIGH to LOW),  and you've waited
    // long enough since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (buttonLeftState != lastButtonLeftState) {
        // reset the debouncing timer
        lastDebounceLeftTime = millis();
    }

    if ((millis() - lastDebounceLeftTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:
        if (!buttonLeftState) {
            // Pullup to 5V => Normally 5V, Pressed 0V
            returnVal = 1;
        }
    }

    lastButtonLeftState = buttonLeftState;
    return returnVal;
}
