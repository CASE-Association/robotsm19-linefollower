#include <Arduino.h>
#include "motor.h"

/*
 * @brief Function for setting up the motor driver
 */
void motorSetup(void){
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Enable the motor driver.
  digitalWrite(STBY, HIGH);
}


/*
 * @brief Function for adjusting the right motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setRightPWM(int speed){
  if(speed > 255)
    speed = 255;
  if(speed < -255)
    speed = -255;
  
  if(speed >= 0){
    /* Right motor forward -> CW */
    // Set the orientation of the motor
    digitalWrite(AIN1, HIGH); 
    digitalWrite(AIN2, LOW); 
    
    analogWrite(PWMB, speed);
  }else{
    /* Right motor reverse -> CCW */
    digitalWrite(AIN1, LOW); 
    digitalWrite(AIN2, HIGH); 
    
    analogWrite(PWMB, -speed);
  }
  
}

/*
 * @brief Function for adjusting the left motor speed.
 * @param speed (int) The disered raw speed. 
 */
void setLeftPWM(int speed){
  if(speed > 255)
    speed = 255;
  if(speed < -255)
    speed = -255;
  
  if(speed >= 0){
    /* Left motor Forward -> CCW */
    // Set the orientation of the motor
    digitalWrite(BIN1, LOW); 
    digitalWrite(BIN2, HIGH); 
    
    analogWrite(PWMB, speed);
  }else{
    /* Left motor -> Reverse -> CW */
    digitalWrite(BIN1, HIGH); 
    digitalWrite(BIN2, LOW); 
    
    analogWrite(PWMB, -speed);
  }
}

