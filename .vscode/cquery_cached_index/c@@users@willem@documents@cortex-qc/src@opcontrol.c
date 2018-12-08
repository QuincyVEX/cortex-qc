/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 //motors
#define ball_collector 1
#define wheel_right 2
#define wheel_left 3
#define ball_launcher_right1 4
#define ball_launcher_left1 5
#define ball_launcher_right2 6
#define ball_launcher_left2 7
#define lift 8
#define manup 9
//int motor value
int ball_collector_power = 0;
int wheel_right_power = 0;
int wheel_left_power = 0;
int ball_launcher_right1_power = 0;
int ball_launcher_left1_power = 0;
int ball_launcher_right2_power = 0;
int ball_launcher_left2_power = 0;
int lift_power = 0;
int manup_power = 0;
/*
void operatorControl() {
  while(1){
    delay(20);

    //movement

    wheel_right_power = joystickGetAnalog(1, 2);
    wheel_left_power = joystickGetAnalog(1, 3);

    motorSet(wheel_right, wheel_right_power);
    motorSet(wheel_left, wheel_left_power);

  }
}
*/
void operatorControl() {
	int powers;
	int turn;
	while (1) {
		powers = joystickGetAnalog(1, 2);
		turn = joystickGetAnalog(1, 3);
		motorSet(2, turn);
		motorSet(3, -powers);
		delay(20);

		if(joystickGetDigital(1, 5, JOY_UP)){
			motorSet(8, 127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN)){
			motorSet(8, -127);
		}
		else{
			motorSet(8, 0);
		}

		if(joystickGetDigital(1, 6, JOY_UP)){
			motorSet(9, 80);
		}
		else if(joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(9, -80);
		}
		else{
			motorSet(9, 0);
		}

	}
}
