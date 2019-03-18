#include "led.h"
#include <Arduino.h>

/*
 * @brief Function for setting up the LEDs
 */
void ledSetup() {
    pinMode(LED_R, OUTPUT);
    pinMode(LED_O, OUTPUT);
    pinMode(LED_PCB, OUTPUT);
}

void testLEDS(){
    //Turn on 1 at a time, then turn off both at the same time.
    LED_R_ON();
    delay(500);

    LED_O_ON();
    delay(500);

    LED_PCB_ON();
    delay(500);

    turnOffLEDS();
    delay(500);
}