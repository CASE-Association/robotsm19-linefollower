/*
   Code for CASE line following robot that will be attending the Robot Championship in Sweden 2019.
   Authors:
   Oskar Johansson - email@email.com
   Isak Åslund - aslundisak@gmail.com
*/

/*
   Things to implement:
   LED - Implemented - Verified
   Button - Implemented - Verified
   Motor - Implemented - Verified
   Encoder - Implemented - NOT TESTED
   Control - (Control loop for maintaining a certain speed and acceleration)
   Sensors - Implemented  - Verified
   Algorithm - (The algorithm used to decide how to drive the robot, this will probably not be needed in the start since the controller will take care of it. Only if we need more advanced techics.
*/

// Important - Rember to only include library files such as <Wire.h> in this file (the main file) because of how the compiler works in Arduino IDE.
#include <Arduino.h>
#include "button.h"
#include "led.h"
#include "sensor.h"
#include "encoder.h"
#include "motor.h"
#include "control.h"
#include "misc.h"

//Used for testing encoders
unsigned long currTime;
unsigned long lastTime;
int osvlad = 0;
int rotSpeed = speedToCounts(50*2);

void setup() {
    Serial.begin(9600);

    ledSetup();
    buttonSetup();
    motorSetup();
    encoderSetup();

    delay(100);
    Serial.println("------  CASE - RobotSM19 - Linefollower  ------");
    Serial.println("------  Press right button to start  ------");

    while(!readButtonRight());
    Serial.println("------ Let's go in 1s ------");
    LED_O_ON();
    delay(1000);
}

void loop() {
    currTime = millis();
    int period = currTime - lastTime;


    //updateEncoders();
    //calcMotorPWM(period);
    
/*
    if(currTime % 1000 > 0 && currTime % 1000 < 100){
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


        Serial.print("----- T: ");
        Serial.print(targetSpeedW);
        Serial.print(" - FB: ");
        Serial.print(encoderFeedbackW);
        Serial.print(" - E: ");
        Serial.print(velErrorW);
        Serial.print(" - PWMW: ");
        Serial.print(posPWMW);


        Serial.print(" - S: ");
        Serial.print(countsToSpeed((leftEncoderChange + rightEncoderChange)/2, period));
        Serial.print("mm/s - Millis: ");
        Serial.println(period);
    }
*/
    lastTime = currTime;

    //delay(10);

}
