/**
  * file motors.h
  *
  * Is used to define the motors globally, so they dont have to be defined for
  * driver control and autonomous modes separately.
*/

#ifndef _MOTORS_H
#define _MOTORS_H
#include "main.h"

  //Set up controller
  extern pros::Controller master(pros::E_CONTROLLER_MASTER);
  //Set up motors
  extern pros::Motor driveLFMotor (DRIVE_LEFT_FRONT_PORT);
  extern pros::Motor driveLBMotor (DRIVE_LEFT_BACK_PORT);
  extern pros::Motor driveRFMotor (DRIVE_RIGHT_FRONT_PORT, true);
  extern pros::Motor driveRBMotor (DRIVE_RIGHT_BACK_PORT, true);
  extern pros::Motor fwLowerMotor (FLYWHEEL_LOWER_PORT, true);
  extern pros::Motor fwUpperMotor (FLYWHEEL_UPPER_PORT);
  extern pros::Motor intakeMotor (INTAKE_PORT);
#endif
