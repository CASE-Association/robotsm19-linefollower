#ifndef CONTROL_H
#define CONTOL_H

extern int targetSpeedX;
extern int encoderFeedbackX;
extern int velErrorX;
extern int posPWMX;
extern int leftEncoderChange;
extern int rightEncoderChange;

void setTargetSpeedX(int speed);
void updateEncoders(void);
void calcMotorPWM(void);


#endif