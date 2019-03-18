#ifndef LED_H
#define LED_H

#define LED_R 2  // D2 - Red
#define LED_O 16 // A2 - Orange
#define LED_PCB 13 // D13 - LED on Arduino Nano PCB 

//Macro functions
#define turnOffLEDS(void) digitalWrite(LED_R, 0); digitalWrite(LED_O, 0); digitalWrite(LED_PCB, 0)
#define LED_R_ON(void) digitalWrite(LED_R, 1)
#define LED_O_ON(void) digitalWrite(LED_O, 1)
#define LED_PCB_ON(void) digitalWrite(LED_PCB, 1)
#define LED_R_OFF(void) digitalWrite(LED_R, 0)
#define LED_O_OFF(void) digitalWrite(LED_O, 0)
#define LED_PCB_OFF(void) digitalWrite(LED_PCB, 0)

void ledSetup(void);
void testLEDS(void);

#endif

