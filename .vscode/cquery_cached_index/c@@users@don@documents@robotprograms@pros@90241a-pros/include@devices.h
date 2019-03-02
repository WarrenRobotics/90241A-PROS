/**
  * file motors.h
  *
  * Is used to define the motors globally, so they dont have to be defined for
  * driver control and autonomous modes separately.
*/

#ifndef DEVICES_H_
  #define DEVICES_H_
  #ifdef _PROS_MAIN_H_
  #include "main.h"
    extern pros::Controller master(E_CONTROLLLER_MASTER);
    extern pros::Motor driveLFMotor(DRIVE_LEFT_FRONT_PORT);
    extern pros::Motor driveLBMotor(DRIVE_LEFT_BACK_PORT);
    extern pros::Motor driveRFMotor(DRIVE_RIGHT_FRONT_PORT);
    extern pros::Motor driveRBMotor(DRIVE_RIGHT_BACK_PORT);
    extern pros::Motor fwLowerMotor(FLYWHEEL_LOWER_PORT);
    extern pros::Motor fwUpperMotor(FLYWHEEL_UPPER_PORT);
    extern pros::Motor intakeMotor(INTAKE_PORT);
  #endif
#endif
