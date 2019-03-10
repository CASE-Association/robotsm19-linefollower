#ifndef MOTOR_H
#define MOTOR_H

// The AIN,BIN, STBY pins might not be correct since a deine with A0 did not work.
#define AIN1 23 // A0
#define AIN2 24 // A1
#define BIN1 25 // A2
#define BIN2 26 // A3
#define STBY 27 // A4
#define PWMA 9  // Right Motor D9
#define PWMB 3  // Left Motor D3



void motorSetup(void);
void setLeftPWM(int);
void setRightPWM(int);


#define turnMotorsOff(void) setLeftPWM(0); setRightPWM(0)

#endif

