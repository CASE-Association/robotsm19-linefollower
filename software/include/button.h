#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

#define BUTTON PIN_A0

void buttonSetup(void);
int readButton(void);

#endif

