/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "portDef.h"
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
 /*

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
*/

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
	int left;
	int right;
	//wait(1000);
	//autonomous();
	while (1) {
		right = joystickGetAnalog(1, 2);
		left = joystickGetAnalog(1, 3);
		motorSet(wheel_right, -right);
		motorSet(wheel_left, left);
		delay(20);
		//lift
		if(joystickGetDigital(1, 5, JOY_UP)){
			motorSet(leftLift, 127);
			motorSet(leftRight, -127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN)){
			motorSet(leftLift, -127);
			motorSet(leftRight, 127);
		}
		else{
			motorSet(leftLift, 0);
			motorSet(leftRight, 0);
		}
		//arm thingy (man up?)
		if(joystickGetDigital(1, 6, JOY_UP)){
			motorSet(manup, 80);
		}
		else if(joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(manup, -80);
		}
		else{
			motorSet(manup, 0);
		}
		//ball launcher
		if(joystickGetDigital(1, 8, JOY_LEFT)){
			motorSet(ball_launcher_right1, 127);
			motorSet(ball_launcher_right2, 127);

			motorSet(ball_launcher_left1, -127);
			motorSet(ball_launcher_left2, -127);
		}
		else{

		}

		//ball intake
		if(joystickGetDigital(1, 8, JOY_UP)){
			motorSet(ball_collector, 127);
		}
		else if(joystickGetDigital(1, 8, JOY_DOWN)){
			motorSet(ball_collector, -127);
		}
		else{
			motorSet(ball_collector, 0);
		}


	}
}
