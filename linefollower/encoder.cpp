#include <Arduino.h>
#include "encoder.h"


int leftEncCounts = 0;
int rightEncCounts = 0;


void encoderSetup(void){
  pinMode(
}

int getLeftEncCount(void){
  return leftEncCounts;
}

int getRightEncCount(void){
  return rightEncCounts;
}

void resetLeftEncCount(void){
  leftEncCounts = 0;
}

void resetRightEncCount(void){
  rightEncCounts = 0;
}
