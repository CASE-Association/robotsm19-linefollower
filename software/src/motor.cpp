#include <Arduino.h>
#include "motor.h"

/*
 * @brief Function for setting up the motor driver
 */
void motorSetup(void) {
    pinMode(LEFTMOTOR, OUTPUT);
    pinMode(RIGHTMOTOR, OUTPUT);
}

/**
 * @brief Function for testing forward and reverse
 * 
 */
void testMotors(void){
    Serial.println("----- Forward -----");
    Serial.println("Left power: 100 -- Right power : 100");
    setLeftPWM(100);
    setRightPWM(100);
    delay(1000);

    Serial.println("----- STOP -----");
    turnMotorsOff();
    delay(2000);

    Serial.println("----- Backwards -----");
    Serial.println("Left power: -100 -- Right power : -100");
    setLeftPWM(-100);
    setRightPWM(-100);
    delay(1000);

    Serial.println("----- STOP -----");
    turnMotorsOff();
    delay(2000);
}

/**
 * @brief Functions for running both motors from zero speed to max and back down. Rotation is forward.
 * 
 */
void motorSweep(void){
    for(int i = 0; i <= 255; i++){
        setLeftPWM(i);
        setRightPWM(i);
        delay(12);
    }

    for(int i = 255; i >= 0; i--){
        setLeftPWM(i);
        setRightPWM(i);
        delay(12);
    }
}

/*
 * @brief Function for adjusting the right motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setRightPWM(int speed) {
    if (speed > 255)
        speed = 255;
    if (speed < -255)
        speed = 0;

    analogWrite(RIGHTMOTOR, speed);
}

/*
 * @brief Function for adjusting the left motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setLeftPWM(int speed) {
    if (speed > 255)
        speed = 255;
    if (speed < -255)
        speed = 0;
    
    analogWrite(LEFTMOTOR, speed);
}
