#ifndef LED_H
#define LED_H

#include <Arduino.h>

#define LED_O PIN_A1 // Orange LED

//Macro functions
#define turnOffLEDS(void) digitalWrite(LED_O, 0)
#define LED_O_ON(void) digitalWrite(LED_O, 1)
#define LED_O_OFF(void) digitalWrite(LED_O, 0)

void ledSetup(void);
void testLEDS(void);

#endif

