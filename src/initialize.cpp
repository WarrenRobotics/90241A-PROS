#include "main.h"

//Define ONLY in this file. See initial values in the initialize function.
//Once defined here, these variables do NOT need to be re-defined in other files
//Controlling variables
int autonomousMode;
int driverMode;
int optionalMode;
//Devices
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor driveLFMotor(DRIVE_LEFT_FRONT_PORT);
pros::Motor driveLBMotor(DRIVE_LEFT_BACK_PORT);
pros::Motor driveRFMotor(DRIVE_RIGHT_FRONT_PORT, true);
pros::Motor driveRBMotor(DRIVE_RIGHT_BACK_PORT, true);
pros::Motor fwUpperMotor(FLYWHEEL_UPPER_PORT);
pros::Motor fwLowerMotor(FLYWHEEL_LOWER_PORT, true);
pros::Motor intakeMotor(INTAKE_PORT);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//Initialize menu selector vairables
	autonomousMode = 1;
	driverMode = 0;
	optionalMode = 0;
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

}
