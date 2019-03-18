#include <Arduino.h>
#include "misc.h"

/**
 * @brief Function that converts counts to speed.
 * 
 * @param counts    (counts/ms)     The counts under a period
 * @param period    (ms)            The period which the counts has accumulated
 * @return float    (mm/s)          The speed in mm/s
 */


float countsToSpeed(int counts, int period){
    // Not Tested - perhaps unit tests should be done here?
    float speed = counts / CPR / GEAR_RATIO * (PI * WHEEL_D); // Convert to mm/period
    speed = speed  * 1000 / period;                           // Convert ms => s
    return speed;
}

