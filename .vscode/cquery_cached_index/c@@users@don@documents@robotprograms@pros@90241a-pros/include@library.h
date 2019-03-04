/**
  * file ports.h
  *
  * This file is used to define the ports of each device plugged
  * into the V5 brain.
  */
  #include "main.h"
/*------------Motor Ports--------------*/
#define DRIVE_LEFT_FRONT_PORT                 10
#define DRIVE_LEFT_BACK_PORT                  2
#define DRIVE_RIGHT_FRONT_PORT                4
#define DRIVE_RIGHT_BACK_PORT                 1
#define FLYWHEEL_LOWER_PORT                   19
#define FLYWHEEL_UPPER_PORT                   11
#define INTAKE_PORT                           3

/*-----------Variables------------*/
extern int autonomousMode;
extern int driverMode;
extern int optionalMode;
