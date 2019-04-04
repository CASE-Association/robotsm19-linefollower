/*
   Code for CASE line following robot that will be attending the Robot Championship in Sweden 2019.
   Authors:
   Oskar Johansson - oskaj@chalmers.se
   Isak Åslund - isakas@chalmers.se
   Stefan Larsson - stel@student.chalmers.se
*/

/*
   Things to implement:
   LED - Implemented - Verified
   Button - Implemented - Verified
   Motor - Implemented - Verified
   Sensors - Implemented - Verified
*/

#include <Arduino.h>
#include "led.h"
#include "button.h"
#include "motor.h"
#include "sensor.h"

void setup() {
    Serial.begin(115200);

    ledSetup();
    buttonSetup();
    motorSetup();
    

    delay(100);
    Serial.println("------  CASE - RobotSM19 - Linefollower  ------");
    Serial.println("------  Press to calibrate  ------");

    while(!readButton());
    sensorSetup();
    delay(50);

    Serial.println("------  Press to START  ------");
    while(!readButton());
    Serial.println("------ Let's go in 1s ------");
    LED_O_ON();
    delay(1000);
}

void loop() {

    //testLEDS();
    //testMotors();  
    testSensors();
    //control();
}
