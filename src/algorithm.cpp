#include <Arduino.h>
#include "algorithm.h"
#include "sensor.h"
#include "motor.h"
#include "control.h"


int lastMiddle = 1;
void control(){
    int middle = readMiddleSensor();
    
    if(middle){
        targetSpeedW = 0;
        targetSpeedX = maxSpeedX;
    }
    else if(lastMiddle != middle)
        targetSpeedX = moveSpeedX;
    else
        targetSpeedX = maxSpeedX;

    if(readLeftSensor())
        targetSpeedW = turnSpeed;
    if(readRightSensor())
        targetSpeedW = -turnSpeed;

    lastMiddle = middle;
}