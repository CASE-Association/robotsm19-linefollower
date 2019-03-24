#ifndef CONTROL_H
#define CONTOL_H

extern int targetSpeedX;
extern int targetSpeedW;
extern int turnSpeed;
extern int moveSpeedX;
extern int maxSpeedX;


extern int encoderFeedbackX;
extern int encoderFeedbackW;
extern int velErrorX;
extern int velErrorW;
extern int accumErrorX;
extern int accumErrorW;
extern int rateErrorX;
extern int rateErrorW;
extern int posPWMX;
extern int posPWMW;
extern int leftEncoderChange;
extern int rightEncoderChange;

void setTargetSpeedX(int speed);
void updateEncoders(void);
void calcMotorPWM(int period);


#endif