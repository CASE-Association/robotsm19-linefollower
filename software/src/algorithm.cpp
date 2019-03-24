#include <Arduino.h>
#include "algorithm.h"
#include "sensor.h"
#include "motor.h"
#include "control.h"
int baseSpeed = 70;
int tSpeed = 50;
int turnMod = 40;
void control(){
    
    
    if(readMiddleSensor()){
        //targetSpeedW = 0;
        setLeftPWM(baseSpeed);
        setRightPWM(baseSpeed);
    }
    if(readLeftSensor()){
        //targetSpeedW = turnSpeed;
        setLeftPWM(tSpeed - turnMod);
        setRightPWM(tSpeed + turnMod);
    }
    if(readRightSensor()){
        //targetSpeedW = -turnSpeed;
        setLeftPWM(tSpeed + turnMod);
        setRightPWM(tSpeed - turnMod);
    }
}