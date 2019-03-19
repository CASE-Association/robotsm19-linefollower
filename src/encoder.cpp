#include <Arduino.h>
#include "encoder.h"

int leftEncCounts = 0;
int rightEncCounts = 0;

// Arduino nano only has 2 interrupt pins so we cna't use interrupts on both channel A and B on the encoder.
// Implemented with interrupts on channel A on both encoders.
void encoderSetup(void) {
    //Right Motor
    pinMode(HALLA1, INPUT);  // No pullup resistor needed, already on the encoder PCB
    pinMode(HALLB1, INPUT);
    attachInterrupt(digitalPinToInterrupt(HALLA1), changeA1, CHANGE);

    //Left Motor
    pinMode(HALLA2, INPUT);
    pinMode(HALLB2, INPUT);
    attachInterrupt(digitalPinToInterrupt(HALLA2), changeA2, CHANGE);

    resetLeftEncCount();
    resetRightEncCount();
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

void changeA1() {
    if (digitalRead(HALLA1)) {
        if (!digitalRead(HALLB1)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    } else {
        if (digitalRead(HALLB1)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    }
}

void changeA2() {
    if (digitalRead(HALLA2)) {
        if (digitalRead(HALLB2)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    } else {
        if (!digitalRead(HALLB2)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    }
}
