/*
   Code for CASE line following robot that will be attending the Robot Championship in Sweden 2019.
   Authors:
   Oskar Johansson - oskaj@chalmers.se
   Isak Åslund - isakas@chalmers.se
   Stefan Larsson - stek@caselabbet.se
*/

/*
   Things to implement:
   LED - Implemented - NOT Verified
   Button - Implemented - NOT Verified
   Motor - Implemented - NOT Verified
   Encoder - NOT Implemented - NOT Verified
   Control - NOT Implemented - NOT Verified
   Sensors - NOT Implemented - NOT Verified
   Algorithm - NOT Implemented - NOT Verified
*/

#include <Arduino.h>
#include "led.h"
#include "button.h"
#include "motor.h"
#include "sensor.h"

#include "control.h"
#include "algorithm.h"
#include "misc.h"

void setup() {
    Serial.begin(115200);

    ledSetup();
    buttonSetup();
    motorSetup();

    delay(100);
    Serial.println("------  CASE - RobotSM19 - Linefollower  ------");
    Serial.println("------  Place middle sensor on line and press right button to start  ------");

    while(!readButton());
    Serial.println("------ Let's go in 1s ------");
    LED_O_ON();
    delay(1000);
}

void loop() {

    //testLEDS();
    //testMotors();  
    //testSensors();
    //updateEncoders();
    //calcMotorPWM(period);
}
