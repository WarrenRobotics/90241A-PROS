/**
  * file motors.h
  *
  * Is used to define the devices globally, so they dont have to be defined for
  * driver control and autonomous modes separately. These include controller
  * objects and motor objects.
*/
#ifndef DEVICES_H_
#define DEVICES_H_
#ifdef _PROS_MAIN_H_
#include "main.h"
extern pros::Controller master;
extern pros::Motor driveLFMotor;
extern pros::Motor driveLBMotor;
extern pros::Motor driveRFMotor;
extern pros::Motor driveRBMotor;
extern pros::Motor fwLowerMotor;
extern pros::Motor fwUpperMotor;
extern pros::Motor intakeMotor;
#endif
#endif // DEVICES_H_
