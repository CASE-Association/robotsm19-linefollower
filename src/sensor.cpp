#include <Arduino.h>
#include "sensor.h"


void sensorSetup(void){
    pinMode(SENSOR_LEFT, INPUT);
    pinMode(SENSOR_MIDDLE, INPUT);
    pinMode(SENSOR_RIGHT, INPUT);
}

int readLeftSensor(){
    return digitalRead(SENSOR_LEFT);
}

int readMiddleSensor(){
    return digitalRead(SENSOR_MIDDLE);
}

int readRightSensor(){
    return digitalRead(SENSOR_RIGHT);
}
