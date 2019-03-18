#include <Arduino.h>
#include "led.h"


/*
 * @brief Function for setting up the LEDs
 */
void ledSetup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

