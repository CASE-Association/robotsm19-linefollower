#ifndef ENCODER_H
#define ENCODER_H


#define HALLA1 4 // Right motor sensor
#define HALLB1 6
#define HALLA2 7 // left motor sensor
#define HALLB2 8

void encoderSetup(void);
int getLeftEncCount(void);
int getRightEncCount(void);
void resetLeftEncCount(void);
void resetRightEncCount(void);

#endif

