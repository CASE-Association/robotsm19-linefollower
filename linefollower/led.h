#ifndef LED_H
#define LED_H

//Names should perhaps be the color of the LED.
#define LED1 1
#define LED2 0

//Macro functions - These have to be tested!
#define turnOffLEDS(void) digitalWrite(LED1, 0); digitalWrite(LED2, 0) 
#define LED1_ON(void) digitalWrite(LED1, ON)
#define LED2_ON(void) digitalWrite(LED2, ON)
#define LED1_OFF(void) digitalWrite(LED1, OFF)
#define LED2_OFF(void) digitalWrite(LED2, OFF)

void ledSetup(void);

#endif

