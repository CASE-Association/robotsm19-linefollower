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

int targetSpeedX = speedToCounts(90*2); // 300 mm/s, * 2 because of rightEncChange + leftEncChange
int targetSpeedW = speedToCounts(0*2);   // Initial rotation is none;
int moveSpeedX    = speedToCounts(50*2);
int maxSpeedX     = speedToCounts(90*2);
int turnSpeed    = speedToCounts(100*2);  // Tweak to turn faster.


int leftBaseSpeed;
int rightBaseSpeed;

int encoderFeedbackX;
int encoderFeedbackW;

int velErrorX;
int velErrorW;

int oldVelErrorX;
int oldVelErrorW;

int posPWMX;
int posPWMW;

float kpX = 0.75;
float kiX = 0.1; // Not Used
float kdX = 0;

float kpW = 1;
float kiW = 0.1; // Not Used
float kdW = 0;

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
 *        Implemented with PD only.
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

	leftBaseSpeed = posPWMX - posPWMW;
    rightBaseSpeed = posPWMX + posPWMW;

	setLeftPWM(leftBaseSpeed);
	setRightPWM(rightBaseSpeed);
}