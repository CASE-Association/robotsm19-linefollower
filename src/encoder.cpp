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

void changeA1() {
    if (digitalRead(HALLA1)) {
        if (!digitalRead(HALLB1)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    } else {
        if (digitalRead(HALLB1)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    }
}

void changeB1() {
    if (digitalRead(HALLB1)) {
        if (digitalRead(HALLA1)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    } else {
        if (!digitalRead(HALLA1)) {
            leftEncCounts++;
        } else {
            leftEncCounts--;
        }
    }
}

void changeA2() {
    if (digitalRead(HALLA2)) {
        if (!digitalRead(HALLB2)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    } else {
        if (digitalRead(HALLB2)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    }
}

void changeB2() {
    if (digitalRead(HALLB2)) {
        if (digitalRead(HALLA2)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    } else {
        if (!digitalRead(HALLA2)) {
            rightEncCounts++;
        } else {
            rightEncCounts--;
        }
    }
}
