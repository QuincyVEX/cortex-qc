#ifndef _portDef_H_
#define _portDef_H_
// Create all the port defintions in one place for easy trouble shooting
#include "API.h"

// ---------- Motor Port Assignments -----------------------------------
#define LM_F_DRIVE 2
#define LM_B_DRIVE 3
#define RM_F_DRIVE 4
#define RM_B_DRIVE 5

// Lift mechnism
#define LIFT_LEFT_M 6
#define LIFT_RIGHT_M 7

// Claw mechanism
#define CLAW_M 8

// ----------- Digital Ports ------------------------------------------
// Drive train encoders
#define QUAD_TOP_LM_PORT 6
#define QUAD_BOTTOM_LM_PORT 7
#define QUAD_TOP_RM_PORT 4
#define QUAD_BOTTOM_RM_PORT 5

// Lift encoders
#define QUAD_TOP_LIFT_PORT 1
#define QUAD_BOTTOM_LIFT_PORT 2

// ----------- Is DEBUGGING ON ---------------------------------------
#define DEBUG_ON true
#define VEXNET_MANUAL false        // turns opcontrol into allowing for
                                  // testing autonomous code
#define VEXNET_TIME 15            // 15 seconds or other time to run
                                  // not yet implemented

// ----------- Setup sensors as needed -------------------------------
// Setup Encoder and other device instances
Encoder encoderLM;
Encoder encoderRM;
Encoder encoderLIFT;

#endif // _portDef_H_
