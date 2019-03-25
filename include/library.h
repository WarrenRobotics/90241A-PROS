/**
  * \file library.h
  *
  * This file is used to define the ports of each device plugged
  * into the V5 brain, declare global variables, and declare
  * smart devices.
  */
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

/*----------------------Add Includes Here----------------------------*/
#include "api.h"
/*-------------------------Device Ports------------------------------*/
#define DRIVE_LEFT_FRONT_PORT                 10
#define DRIVE_LEFT_BACK_PORT                  2
#define DRIVE_RIGHT_FRONT_PORT                4
#define DRIVE_RIGHT_BACK_PORT                 1
#define FLYWHEEL_LOWER_PORT                   19
#define FLYWHEEL_UPPER_PORT                   11
#define INTAKE_PORT                           3
/*---------------------------Variables-------------------------------*/

/*-------------------------Declare Devices---------------------------*/
//Controller
extern pros::Controller master;
//Motors
extern pros::Motor driveLFMotor;
extern pros::Motor driveLBMotor;
extern pros::Motor driveRFMotor;
extern pros::Motor driveRBMotor;
extern pros::Motor fwUpperMotor;
extern pros::Motor fwLowerMotor;
extern pros::Motor intakeMotor;

#endif // _LIBRARY_H_
