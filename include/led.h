#ifndef LED_H
#define LED_H

// Names should perhaps be the color of the LED.
#define LED1 2  // D2 - Red
#define LED2 16 // A2 - Orange
#define LED3 13 // D13 - LED on Arduino Nano PCB 

//Macro functions - These have to be tested!
#define turnOffLEDS(void) digitalWrite(LED1, 0); digitalWrite(LED2, 0); digitalWrite(LED3, 0)
#define LED1_ON(void) digitalWrite(LED1, 1)
#define LED2_ON(void) digitalWrite(LED2, 1)
#define LED3_ON(void) digitalWrite(LED3, 1)
#define LED1_OFF(void) digitalWrite(LED1, 0)
#define LED2_OFF(void) digitalWrite(LED2, 0)
#define LED3_OFF(void) digitalWrite(LED3, 0)

void ledSetup(void);
void testLEDS(void);

#endif

