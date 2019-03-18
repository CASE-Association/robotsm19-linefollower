#include <Arduino.h>
#include "sensor.h"


void sensorSetup(void){
    pinMode(SENSOR_LEFT, INPUT);
    pinMode(SENSOR_MIDDLE, INPUT);
    pinMode(SENSOR_RIGHT, INPUT);
}

void testSensors(void){
    Serial.print("Left: ");
    Serial.print(readLeftSensor());
    Serial.print("  ---  Middle: ");
    Serial.print(readMiddleSensor());
    Serial.print("  ---  Right: ");
    Serial.println(readRightSensor());
    delay(100);
}


// BLACK => No LED => 5V
// White => LED => 0V
int readLeftSensor(){
    int reading = analogRead(SENSOR_LEFT);
    if(reading > 512)
        return 1;
    else
        return 0;
}

int readMiddleSensor(){
    return digitalRead(SENSOR_MIDDLE);
}

int readRightSensor(){
    int reading = analogRead(SENSOR_RIGHT);
    if(reading > 512)
        return 1;
    else
        return 0;
}
