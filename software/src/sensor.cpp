#include <Arduino.h>
#include <QTRSensors.h> // Pololu Library
#include "sensor.h"
#include "motor.h"

// Create the sensor object
QTRSensors qtr;
// Array for storing the sensor readings.
uint16_t sensorValues[SENSOR_COUNT];

int lastError;
int lastTime;
float KP = 0.06;
float KD = 0.8;
int baseSpeed = 150;

void sensorSetup(void){
    qtr.setTypeRC();
    qtr.setSensorPins((const uint8_t[]){2, 3, 4, 5, 6, 7, 8, 9}, SENSOR_COUNT);
    qtr.setEmitterPin(EMITTER_PIN);

    Serial.println("----    Calibrating sensors, move robot over the line for 5s, until red LED goes low   ----");
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    for (uint16_t i = 0; i < 256; i++) {
        qtr.calibrate();
    }
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("----    Calibration done    ----");

    // Print the calibration maximum values measured when emitters were off
    Serial.println("----    Minimum values with IR OFF   ----");
    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        Serial.print(qtr.calibrationOn.minimum[i]);
        Serial.print(' ');
    }
    Serial.println();

    // Print the calibration maximum values measured when emitters were on
    Serial.println("----    Maximum values with IR ON   ----");
    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        Serial.print(qtr.calibrationOn.maximum[i]);
        Serial.print(' ');
    }
}

void testSensors(void){
    // print the sensor values as numbers from 0 to 1000, where 0 means maximum
    // reflectance and 1000 means minimum reflectance, followed by the line
    // position

    qtr.read(sensorValues);
    for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
    }

    int position = qtr.readLineBlack(sensorValues);
    int error = position - 3500;
    Serial.print("---- \t Position: "); Serial.print(position);
    Serial.print("\t Error: "); Serial.println(error);

    delay(100);
}

void control(void){
    int position = qtr.readLineBlack(sensorValues);
    int error = position - 3500;
    
    int motorSpeed = KP * error + KD * (error - lastError);
    lastError = error;

    int leftSpeed = baseSpeed - motorSpeed;
    int rightSpeed = baseSpeed + motorSpeed;

    setLeftPWM(leftSpeed);
    setRightPWM(rightSpeed);

    //Perhaps a delay is nice here?
}
