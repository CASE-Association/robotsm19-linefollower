/**
 * @brief 
 * 
 */
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
#include "encoder.h"
#include "led.h"
#include "motor.h"
#include "sensor.h"
#include "misc.h"

//Used for testing encoders
unsigned long time;
unsigned long lastTime;


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

    //Writing to STBY on the motor driver should not be needed here, it doesn't work in in the setup for some reason.
    //Try putting it in the setup but at the buttom.
    //digitalWrite(STBY, HIGH);
    //testMotors();
    
    //motorSweep();

    //testMotors();
    /*
    // Testing encoders
    time = millis();
    int period = time - lastTime;

    Serial.print("RightEnc CNT: ");
    Serial.print(getRightEncCount());
    Serial.print(" -- ");
    Serial.print("LeftEnc CNT: ");
    Serial.print(getLeftEncCount());
    Serial.println();

    Serial.println("Time: " + time);
    Serial.println("LastTime: " + lastTime);
    Serial.println("Period: " + period);
    Serial.print("Speed: ");
    Serial.println(countsToSpeed((getRightEncCount() + getLeftEncCount())/2, period));
    lastTime = time; 
    

    delay(100);
    */
}
