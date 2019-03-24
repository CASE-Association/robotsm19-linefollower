#ifndef MOTOR_H
#define MOTOR_H

#define AIN1 14 // A0
#define AIN2 15 // A1
#define BIN1 18 // A4
#define BIN2 19 // A5
#define STBY 6  // D6
#define PWMA 9  // D9 - Right Motor 
#define PWMB 5  // D5 - Left Motor 



void motorSetup(void);
void setLeftPWM(int);
void setRightPWM(int);
void testMotors(void);
void motorSweep(void);


#define turnMotorsOff(void) setLeftPWM(0); setRightPWM(0)

#endif

