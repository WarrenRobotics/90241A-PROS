/**
  * \file pre_auton_menu.h
  *
  * Declares all the variables and methods used for the pre-autonomous menu
  * chooser.
  */

#ifndef _PRE_AUTON_MENU_
#define _PRE_AUTON_MENU_

/*----------------------Add Includes Here----------------------------*/
#include "api.h"
#include "pros/apix.h"
/*----------------------Define variables----------------------------*/
extern const char *autonMode;
extern const char *driverMode;

#ifdef __cplusplus
extern "C" {
#endif

/*----------------Define only C++ function headers here---------------*/

/**
  * The method that contains the pre-autonomous menu. Should be run in a
  * separate task. Since the LVGL menu is persistent, if does not require
  * an infinite loop to operate.
  */
void menu_task(void* param);

#ifdef __cplusplus
}
#endif

#endif // _PRE_AUTON_MENU
