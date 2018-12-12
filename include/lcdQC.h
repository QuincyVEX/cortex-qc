#ifndef _LCD_H_
#define _LCD_H_

#include "API.h"

// ARRAYS OF SCRIPTS AND TITLES, NEED TO BE DEFINED ELSEWHERE //
#define NUM_SCRIPTS 5
extern const char* titles[];
extern void (*scripts[])();

// SCRIPT SELECTION //

/**
 * @brief Initializes the LCD on the given port and sets the port for future use with liblcd.
 *
 * @param port
 *        The uart port for the LCD to be initialized.
 */
void lcdScriptInit(FILE* port);

/**
 * @brief Runs the LCD Script Selection process. This runs in a task and will not prevent normal execution.
 */
void lcdScriptSelect();

/**
 * @brief Runs the selected autonomous script. Nothing will run if a script was not selected with lcdScriptSelect().
 */
void lcdScriptExecute();

// GENERAL USE //

/**
 * @brief Prints to the LCD initialized with lcdScriptInit with the text centered on the display.
 */
void lcdPrintCentered(unsigned char line, const char* string);

/**
 * Scripts which are selected through the LCD chooser
 */

/*void exampleScript1();
void exampleScript2();
void exampleScript3();
*/
void autoSkill();
void autoRedLeft();
void autoRedRight();
void autoBlueLeft();
void autBlueRight();

#endif
