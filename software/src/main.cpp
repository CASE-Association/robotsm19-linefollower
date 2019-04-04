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
   Motor - NOT Implemented - NOT Verified
   Encoder - NOT Implemented - NOT Verified
   Control - NOT Implemented - NOT Verified
   Sensors - NOT Implemented - NOT Verified
   Algorithm - NOT Implemented - NOT Verified
*/

#include <Arduino.h>
#include "button.h"
#include "led.h"
#include "sensor.h"
#include "encoder.h"
#include "motor.h"
#include "control.h"
#include "algorithm.h"
#include "misc.h"

//Used for testing encoders
unsigned long currTime;
unsigned long lastTime;

void setup() {
    Serial.begin(115200);

    ledSetup();
    buttonSetup();
    motorSetup();
    encoderSetup();

    delay(100);
    Serial.println("------  CASE - RobotSM19 - Linefollower  ------");
    Serial.println("------  Place middle sensor on line and press right button to start  ------");

    while(!readButtonRight());
    Serial.println("------ Let's go in 1s ------");
    LED_O_ON();
    delay(1000);
}

void loop() {
    currTime = millis();
    //int period = currTime - lastTime;

    //testMotors();
    control();    
    //testSensors();
    //updateEncoders();
    //calcMotorPWM(period);

    /*
    if(currTime % 1000 > 0 && currTime % 1000 < 10){
        Serial.print("L: ");
        Serial.print(leftEncoderChange);
        Serial.print(" - R: ");
        Serial.print(rightEncoderChange);
        Serial.print(" - T: ");
        Serial.print(targetSpeedX);
        Serial.print(" - FB: ");
        Serial.print(encoderFeedbackX);
        Serial.print(" - E: ");
        Serial.print(velErrorX);
        Serial.print(" - PWMX: ");
        Serial.print(posPWMX);
        */

/*
        Serial.print("----- T: ");
        Serial.print(targetSpeedW);
        Serial.print(" - FB: ");
        Serial.print(encoderFeedbackW);
        Serial.print(" - E: ");
        Serial.print(velErrorW);
        Serial.print(" - PWMW: ");
        Serial.print(posPWMW);
*/
/*
        Serial.print(" - S: ");
        Serial.print(countsToSpeed((leftEncoderChange + rightEncoderChange)/2, period));
        Serial.print("mm/s - Millis: ");
        Serial.println(period);
    }
*/
    lastTime = currTime;
}
