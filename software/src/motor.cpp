#include <Arduino.h>
#include "motor.h"


/*
 * @brief Function for setting up the motor driver
 */
void motorSetup(void) {
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(STBY, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);

    // Enable the motor driver and stop.
    digitalWrite(STBY, HIGH);
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

void motorSweep(void){
    for(int i = 0; i <= 255; i++){
        setLeftPWM(i);
        setRightPWM(i);
        delay(12);
    }

    delay(1000);

    for(int i = 255; i >= 0; i--){
        setLeftPWM(i);
        setRightPWM(i);
        delay(12);
    }
    
    delay(1000);


}

/*
 * @brief Function for adjusting the right motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setRightPWM(int speed) {
    if (speed > 255)
        speed = 255;
    if (speed < -255)
        speed = -255;

    if (speed >= 0) {
        /* Right motor forward -> CW */
        // Set the orientation of the motor
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);

        analogWrite(PWMA, speed);
    } else {
        /* Right motor reverse -> CCW */
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);

        analogWrite(PWMA, -speed);
    }
}

/*
 * @brief Function for adjusting the left motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setLeftPWM(int speed) {
    if (speed > 255)
        speed = 255;
    if (speed < -255)
        speed = -255;

    if (speed >= 0) {
        /* Left motor Forward -> CCW */
        // Set the orientation of the motor
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);

        analogWrite(PWMB, speed);
    } else {
        /* Left motor -> Reverse -> CW */
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);

        analogWrite(PWMB, -speed);
    }
}
