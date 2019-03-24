#ifndef ENCODER_H
#define ENCODER_H


#define HALLA1 3 // Right motor sensor
#define HALLB1 8

#define HALLA2 2 // left motor sensor
#define HALLB2 4

// Public functions
void encoderSetup(void);
int getLeftEncCount(void);
int getRightEncCount(void);
void resetLeftEncCount(void);
void resetRightEncCount(void);

// Private functions
void changeA1(void);
void changeB1(void);
void changeA2(void);
void changeB2(void);



#endif


