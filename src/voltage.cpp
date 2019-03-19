// Voltage reading function for reading battery Voltage
#include <Arduino.h>
#include "voltage.h"

int getVoltage(void){
return analogRead(voltagePin) * voltageDivConst;
}