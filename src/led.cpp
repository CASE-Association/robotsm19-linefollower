#include "led.h"
#include <Arduino.h>

/*
 * @brief Function for setting up the LEDs
 */
void ledSetup() {
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void testLEDS(){
    //Turn on 1 at a time, then turn off both at the same time.
    LED1_ON();
    delay(500);

    LED2_ON();
    delay(500);

    LED3_ON();
    delay(500);

    turnOffLEDS();
}