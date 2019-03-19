#ifndef SENSOR_H
#define SENSOR_H

#define SENSOR_LEFT     21    // A7
#define SENSOR_MIDDLE   17    // A3 on now - D10 on new PCB 
#define SENSOR_RIGHT    20    // A6

void sensorSetup(void);
void testSensors(void);

int readLeftSensor(void);
int readMiddleSensor(void);
int readRightSensor(void);


#endif