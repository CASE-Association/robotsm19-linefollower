#include <Arduino.h>
#include "encoder.h"


int leftEncCounts = 0;
int rightEncCounts = 0;

void encoderSetup(void) {
    //Right Motor
    pinMode(HALLA1, INPUT);  // No pullup resistor needed, already on the encoder PCB
    pinMode(HALLB1, INPUT);
    attachInterrupt(digitalPinToInterrupt(HALLA1), changeA1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(HALLB1), changeB1, CHANGE);

    //Left Motor
    pinMode(HALLA2, INPUT);
    pinMode(HALLB2, INPUT);
    attachInterrupt(digitalPinToInterrupt(HALLA2), changeA2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(HALLB2), changeB2, CHANGE);
}

int getLeftEncCount(void) {
    return leftEncCounts;
}

int getRightEncCount(void) {
    return rightEncCounts;
}

void resetLeftEncCount(void) {
    leftEncCounts = 0;
}

void resetRightEncCount(void) {
    rightEncCounts = 0;
}

void changeA1(){
    (digitalRead(HALLA1) ? 
    (digitalRead(HALLB1) ? leftEncCounts-- : leftEncCounts++) :  
    (digitalRead(HALLB1 ? leftEncCounts ++ : leftEncCounts--)));
}

void changeA2(){
    (digitalRead(HALLA2) ? 
    (digitalRead(HALLB2) ? leftEncCounts-- : leftEncCounts++) :  
    (digitalRead(HALLB2 ? leftEncCounts ++ : leftEncCounts--)));
}

