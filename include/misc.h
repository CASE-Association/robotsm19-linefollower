#ifndef MISC_H
#define MISC_H

#define WHEEL_D     42.0          // mm
#define GEAR_RATIO  10.0          // 10:1
#define CPR         6.0             // Counts Per Revolution, halfed because only using 2 interrupts.

float countsToSpeed(int counts, int period);
int speedToCounts(int speed);


#endif
