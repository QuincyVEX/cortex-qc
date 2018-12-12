#include "main.h"    // includes API.h and other headers
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
#include "portdef.h" // All port defintions on the cortex
#include "lcd.h"

void chassisSet(int left, int right) {
  motorSet(LM_F_DRIVE, left);
  motorSet(RM_F_DRIVE, -right);
  motorSet(LM_B_DRIVE, left);
  motorSet(RM_B_DRIVE, -right);
}

void drivePID() {
  // USE PD to drive straight forever
  int masterPower = 30;
  int slavePower = 30;
  int error = 0;
  int kp = 5;

   //Reset the encoders.
   encoderReset(encoderLM);
   encoderReset(encoderRM);
   //Repeat ten times a second.
    while(true)
    {
      //Set the motor powers to their respective variables.
      motorSet(LM_F_DRIVE, masterPower);
      motorSet(LM_B_DRIVE, masterPower);
      motorSet(RM_F_DRIVE, -slavePower);
      motorSet(RM_B_DRIVE, -slavePower);

      error = encoderGet(encoderLM) - encoderGet(encoderRM);
      slavePower += error / kp;

      //Reset the encoders every loop.
      encoderReset(encoderLM);
      encoderReset(encoderRM);

      wait(100);
    }
}

void driveForDistancePID(int distance, int speed) {
  lcdPrint(uart1, 1, "Compete - forDistPID");
  lcdPrint(uart1, 2, "Distance: %d ", distance);

  float wheelCircum = WHEEL_DIAMETER * 3.14;
  float motorDegree = (distance / wheelCircum) * 360;  // cast into full degrees

  if(DEBUG_ON) {
    printf("Dist: %1.2f \n", motorDegree);
    wait(200);                        // Let terminal catch up
  }

  int totalTicks = 0;               // track total trveled
  int slavePower = speed - 5;
  int error = 0;
  int kp = 5;

  encoderReset(encoderLM);
  encoderReset(encoderRM);

  while(abs(totalTicks) < motorDegree)
  {
    motorSet(LM_F_DRIVE, speed);
    motorSet(LM_B_DRIVE, speed);
    motorSet(RM_F_DRIVE, -slavePower);
    motorSet(RM_B_DRIVE, -slavePower);

    error = encoderGet(encoderLM) - encoderGet(encoderRM);
    slavePower += error / kp;

    wait(100);

    //Add this iteration's encoder values to totalTicks.
    totalTicks+= encoderGet(encoderLM);
    if(DEBUG_ON) {
      printf("error: %d", error);
      printf(" slavePower: %d", slavePower);
      printf(" totalTicks: %d \n", totalTicks);
    }
  }
  motorSet(LM_F_DRIVE, 0);
  motorSet(LM_B_DRIVE, 0);
  motorSet(RM_F_DRIVE, 0);
  motorSet(RM_B_DRIVE, 0);
}


void pivotTurn(int direction, int speed, float angle, bool gyro) {
  // direction -- 1 = left turn, 0 = right pivotTurn
  // speed -- -127 -- 127
  // angle -- desired turn angle in degrees
  // gyro -- 0 = no gyro used, 1 = use gyro for turn.
  // Assumes a quadriatic encoder - 360 tics = 360 degrees

  // pivotTurn - turn radius is 1/2 * dimaeter of wheel base
  float turnCircum = WHEEL_BASE * 3.14;
  float wheelCircum = WHEEL_DIAMETER * 3.14;

  float motorDegree = (((angle/360) * turnCircum) / wheelCircum) * 360;

  if(DEBUG_ON) {
    printf("turnCricum: %1.2f \n", turnCircum);
    printf("wheelCricum: %1.2f \n", wheelCircum);
    printf("turn Angle: %1.2f \n", angle);
    printf("motorDegree: %1.2f \n", motorDegree);

    lcdPrint(uart1, 1, "Compete - pivotTurn");
    lcdPrint(uart1, 2, "Mdegree: %1.1f Deg", motorDegree);
  }

  if(direction == 1) {
    // Left turn
    // we need todo a while loop and count until we get to motorDegree
    // on quadriatic encoders
    encoderReset(encoderLM);
    wait(10);                   // give encoder time to reset

    while(encoderGet(encoderLM) <= motorDegree) {
      if(DEBUG_ON){
        printf("encoderLM: %d \n", encoderGet(encoderLM));
      }
      motorSet(LM_F_DRIVE, speed);
      motorSet(RM_F_DRIVE, speed);
      motorSet(LM_B_DRIVE, speed);
      motorSet(RM_B_DRIVE, speed);
      //wait(1);
    }
  } else {
    // Right turn
    // we need todo a while loop and count until we get to motorDegree
    // on quadriatic encoders
    encoderReset(encoderRM);

    while(encoderGet(encoderRM) <= motorDegree) {
      if(DEBUG_ON){
        printf("encoderRM: %d \n", encoderGet(encoderRM));
      }
      motorSet(LM_F_DRIVE, -speed);
      motorSet(RM_F_DRIVE, -speed);
      motorSet(LM_B_DRIVE, -speed);
      motorSet(RM_B_DRIVE, -speed);
      //wait(20);
    }
  }
}
