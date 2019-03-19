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

int targetSpeedX = speedToCounts(300*2); // 300 mm/s, * 2 because of rightEncChange + leftEncChange
long encoderFeedbackX;
int velErrorX;
int oldVelErrorX;
int posPWMX;

float kpX = 0.2;
float kiX = 0.1;
float kdX = 0;

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
 *        Implemented with P only.
 * 
 * @param period (ms) The time period between calls.
 */
void calcMotorPWM(int period){    
	encoderFeedbackX = (rightEncoderChange + leftEncoderChange) * 1000.0/period;
	//encoderFeedbackW = rightEncoderChange - leftEncoderChange;	
	
	//rotationalFeedback = encoderFeedbackW;
	
	velErrorX = targetSpeedX - encoderFeedbackX;
	//posErrorW += curSpeedW - rotationalFeedback;
	
	posPWMX = kpX * velErrorX + kdX * (velErrorX - oldVelErrorX);
	//posPWMW = kpW * posErrorW + kdW * (posErrorW - oldPosErrorW);
	
	oldVelErrorX = velErrorX;
	//oldPosErrorW = posErrorW;

	//leftBaseSpeed = posPwmX - posPwmW;
	//rightBaseSpeed = posPwmX + posPwmW;

	setLeftPWM(posPWMX);
	setRightPWM(posPWMX);
}