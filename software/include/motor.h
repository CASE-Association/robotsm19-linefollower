#ifndef MOTOR_H
#define MOTOR_H

#define RIGHTMOTOR 10 // D10 - Right Motor 
#define LEFTMOTOR 11  // D11 - Left Motor 

void motorSetup(void);
void setLeftPWM(int);
void setRightPWM(int);
void testMotors(void);
void motorSweep(void);


#define turnMotorsOff(void) setLeftPWM(0); setRightPWM(0)

#endif

