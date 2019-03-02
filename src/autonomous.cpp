#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  //Controller
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	//Motors
	pros::Motor driveLFMotor(DRIVE_LEFT_FRONT_PORT);
	pros::Motor driveLBMotor(DRIVE_LEFT_BACK_PORT);
	pros::Motor driveRFMotor(DRIVE_RIGHT_FRONT_PORT);
	pros::Motor driveRBMotor(DRIVE_RIGHT_BACK_PORT);
	pros::Motor fwUpperMotor(FLYWHEEL_UPPER_PORT);
	pros::Motor fwLowerMotor(FLYWHEEL_LOWER_PORT);
	pros::Motor intakeMotor(INTAKE_PORT);
  
}
