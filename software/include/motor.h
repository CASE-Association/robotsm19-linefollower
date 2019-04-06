#ifndef MOTOR_H
#define MOTOR_H

#define RIGHTMOTOR 10 // D10 - Right Motor 
#define LEFTMOTOR 11  // D11 - Left Motor 
#define AIN1 PIN_A4
#define AIN2 PIN_A5
#define BIN1 PIN_A3 
#define BIN2 PIN_A2 

void motorSetup(void);
void setLeftPWM(int);
void setRightPWM(int);
void testMotors(void);
void motorSweep(void);


#define turnMotorsOff(void) setLeftPWM(0); setRightPWM(0)

#endif

