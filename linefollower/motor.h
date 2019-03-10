#ifndef MOTOR_H
#define MOTOR_H

//Motor driver pins AIN1, AIN2, BIN1, BIN2, STBY has not yet been assigned to pins
#define PWMA 9
#define PWMB 3


void motorSetup(void);
void setLeftPWM(int);
void setRightPWM(int);



#endif

