#include <Arduino.h>
#include <QTRSensors.h>
QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

const uint8_t leftMotor = PA7;
const uint8_t rightMotor = PB0;
const uint8_t button = PB3; 
int lastError;
int lastTime;
float KP = 0.06;
float KD = 0.8;

/* 
Drifter: KP = 0.04, KD = 0.4
*/

int baseSpeed = 150;

void setup() {
    Serial.begin(9600);
    Serial.println("---- Setting up system ----");
    pinMode(leftMotor, OUTPUT);
    pinMode(rightMotor, OUTPUT);
    pinMode(button, INPUT_PULLUP);


    // configure the sensors
    qtr.setTypeRC();
    qtr.setSensorPins((const uint8_t[]){PA9, PA8, PB15, PB14, PA11, PB13, PB12, PA10}, SensorCount);
    qtr.setEmitterPin(2);

    delay(500);
    Serial.println("---- Waiting for button press to start ----");
    while(digitalRead(button));

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("----    Calibrating sensors, move robot over the line for 5s, until red led stops   ----");

    for (uint16_t i = 0; i < 256; i++) {
        qtr.calibrate();
    }
    digitalWrite(LED_BUILTIN, LOW);  // turn off Arduino's LED to indicate we are through with calibration
    Serial.println("----    Calibration done    ----");

    for (uint8_t i = 0; i < SensorCount; i++) {
        Serial.print(qtr.calibrationOn.minimum[i]);
        Serial.print(' ');
    }
    Serial.println();

    // print the calibration maximum values measured when emitters were on
    for (uint8_t i = 0; i < SensorCount; i++) {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }
    Serial.println("------------------------ LET'S GO!!!! ----------------------------");
    Serial.println();
    delay(1000);
}

void loop() {
    /*
    // read calibrated sensor values and obtain a measure of the line position
    // from 0 to 5000 (for a white line, use readLineWhite() instead)
    int currTime = millis();
    int timeDiff = currTime - lastTime; 
    lastTime = currTime;
    int position = qtr.readLineBlack(sensorValues);
    int error = position - 3500;

    int motorSpeed = KP * error + KD * (error - lastError);
    lastError = error;

    int leftSpeed = baseSpeed - motorSpeed;
    int rightSpeed = baseSpeed + motorSpeed;

    if(leftSpeed > 255)
        leftSpeed = 255;
    else if(leftSpeed < 0)
        leftSpeed = 0;

    if(rightSpeed > 255)
        rightSpeed = 255;
    else if(rightSpeed < 0)
        rightSpeed = 0;

    analogWrite(leftMotor, leftSpeed);
    analogWrite(rightMotor, rightSpeed);
*/


    // print the sensor values as numbers from 0 to 1000, where 0 means maximum
    // reflectance and 1000 means minimum reflectance, followed by the line
    // position
    for (uint8_t i = 0; i < SensorCount; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
    }
    delay(150);
    /*
    Serial.print("Position: ");
    Serial.print(position);
    Serial.print("    Error: ");
    Serial.print(error);
    Serial.print("   Control Signal: ");
    Serial.print(motorSpeed);
    Serial.print("L: ");
    Serial.print(leftSpeed);
    Serial.print("R: ");
    Serial.print(rightSpeed);
    Serial.println();

    delay(150);
    */
}
