#ifndef _CHASSIS_H_
#define _CHASSIS_H_

#include "stdbool.h"

#define WHEEL_DIAMETER 4      // diameter of drive wheels
#define WHEEL_BASE 10         // wheel base in inches left to right wheel

#define ARCADE_DRIVE false  // when false it runs tank mode, if true
                              /// we will run ARCADE mode

#define JOY_SCALE .5        // scale the joysticks to 50%

// Sets the speeds of the left and right wheels of the chassis
void chassisSet(int left, int right);

// drive forward with PID tankControl
void drivePID();

// drive for defined distance in inches with PID support
void driveForDistancePID(int distance, int speed);

// create pivot turn function
void pivotTurn(int direction, int speed, float angle, bool gyro);

// create swing turn function
void swingTurn(int direction, int speed, float angle, bool gyro);

#endif // _CHASSIS_H_
