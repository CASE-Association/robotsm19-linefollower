#ifndef SENSOR_H
#define SENSOR_H

#define SENSOR_LEFT     13
#define SENSOR_MIDDLE   17    // A3
#define SENSOR_RIGHT    21    // A7 - Not shown in pinout, just based on logic guess

void sensorSetup(void);

int readLeftSensor(void);
int readMiddleSensor(void);
int readRightSensor(void);


#endif