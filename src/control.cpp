#include <Arduino.h>
#include "control.h"
#include "encoder.h"
#include "motor.h"
#include "misc.h"

int leftEncoder;
int rightEncoder;
int leftEncoderOld = 0;
int rightEncoderOld = 0;;
int rightEncoderChange;
int leftEncoderChange;

int targetSpeedX = speedToCounts(150*2); // 300 mm/s, * 2 because of rightEncChange + leftEncChange
int targetSpeedW = speedToCounts(50*2);   // no rotation. 

int encoderFeedbackX;
int encoderFeedbackW;

int velErrorX;
int velErrorW;

int oldVelErrorX;
int oldVelErrorW;

int posPWMX;
int posPWMW;

float kpX = 0.5;
float kiX = 0.1;
float kdX = 0.1;

float kpW = 0.5;
float kiW = 0.1;
float kdW = 0.1;

/**
 * @brief Function for updating the encoder variables for the control loop.
 * 
 */
void updateEncoders(void){
	leftEncoder = getLeftEncCount();
	rightEncoder = getRightEncCount();

	leftEncoderChange = leftEncoder - leftEncoderOld;
	rightEncoderChange = rightEncoder - rightEncoderOld;

	leftEncoderOld = leftEncoder;
	rightEncoderOld = rightEncoder;
}

/**
 * @brief Function for running the control loop for velocity control.
 *        Implemented with a PD.
 * 
 * @param period (ms) The time period between calls.
 */
void calcMotorPWM(int period){    
	encoderFeedbackX = (rightEncoderChange + leftEncoderChange) * 1000.0 / period;
	encoderFeedbackW = (rightEncoderChange - leftEncoderChange) * 1000.0 / period;	
	
	velErrorX = targetSpeedX - encoderFeedbackX;
	velErrorW = targetSpeedW - encoderFeedbackW;
	
	posPWMX = kpX * velErrorX + kdX * (velErrorX - oldVelErrorX);
	posPWMW = kpW * velErrorW + kdW * (velErrorW - oldVelErrorW);
	
	oldVelErrorX = velErrorX;
	oldVelErrorW = velErrorW;

	int leftBaseSpeed = posPWMX - posPWMW;
	int rightBaseSpeed = posPWMX + posPWMW;

	setLeftPWM(leftBaseSpeed);
	setRightPWM(rightBaseSpeed);
}