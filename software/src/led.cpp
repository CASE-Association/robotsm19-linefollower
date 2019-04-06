#include "led.h"
#include <Arduino.h>

/*
 * @brief Function for setting up the LEDs
 */
void ledSetup() {
    pinMode(LED_O, OUTPUT);
}

/**
 * @brief Function for testing the LEDS. Turns on and off the leds 2 times to try all functions.
 * 
 */
void testLEDS(){
    // Try all functions
    LED_O_ON();
    delay(500);

    LED_O_OFF();
    delay(500);

    LED_O_ON();
    delay(500);

    turnOffLEDS();
    delay(500);
}