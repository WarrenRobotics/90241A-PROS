#include "main.h"

#define DRIVE_LEFT_FRONT_PORT 10
#define DRIVE_LEFT_BACK_PORT 2
#define DRIVE_RIGHT_FRONT_PORT 4
#define DRIVE_RIGHT_BACK_PORT 1
#define FLYWHEEL_LOWER_PORT 19
#define FLYWHEEL_UPPER_PORT 11
#define INTAKE_PORT 3

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	//Set up controller
		pros::Controller master(pros::E_CONTROLLER_MASTER);
		//Set up motors
		pros::Motor driveLFMotor (DRIVE_LEFT_FRONT_PORT);
		pros::Motor driveLBMotor (DRIVE_LEFT_BACK_PORT);
		pros::Motor driveRFMotor (DRIVE_RIGHT_FRONT_PORT, true);
		pros::Motor driveRBMotor (DRIVE_RIGHT_BACK_PORT, true);
		pros::Motor fwLowerMotor (FLYWHEEL_LOWER_PORT, true);
		pros::Motor fwUpperMotor (FLYWHEEL_UPPER_PORT);
		pros::Motor intakeMotor (INTAKE_PORT);
		//Initialize shortcut variables
		short leftJoy_x;
		short leftJoy_y;
		short rightJoy_x;
		short rightJoy_y;
		bool leftTriggerUp;
		bool leftTriggerDown;
		bool rightTriggerUp;
		bool rightTriggerDown;
		bool btnA;
		bool btnB;
		bool btnX;
		bool btnY;
		bool btnUp;
		bool btnDown;
		bool btnLeft;
		bool btnRight;
		//Initialize driver control variables
		bool flyWheelToggle = false;
		while (true) {
			//Set variables
			leftJoy_x = (short)master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
			leftJoy_y = (short)master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
			rightJoy_x = (short)master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
			rightJoy_y = (short)master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
			leftTriggerUp = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
			leftTriggerDown = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
			rightTriggerUp = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
			rightTriggerDown = master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
			btnA = master.get_digital(pros::E_CONTROLLER_DIGITAL_A);
			btnB = master.get_digital(pros::E_CONTROLLER_DIGITAL_B);
			btnX = master.get_digital(pros::E_CONTROLLER_DIGITAL_X);
			btnY = master.get_digital(pros::E_CONTROLLER_DIGITAL_Y);
			btnUp = master.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
			btnDown = master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
			btnLeft = master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
			btnRight = master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
			//Drivetrain
			driveLFMotor.move(leftJoy_y);
			driveLBMotor.move(leftJoy_y);
			driveRFMotor.move(rightJoy_y);
			driveRBMotor.move(rightJoy_y);
			//Flywheel
			if(btnX){
				flyWheelToggle = true;
			}
			if(btnA){
				flyWheelToggle = true;
			}
			if(flyWheelToggle){
				fwUpperMotor.move(127);
				fwLowerMotor.move(127);
			}else{
				fwUpperMotor.move(0);
				fwLowerMotor.move(0);
			}
			//Intake
			if(rightTriggerUp){
				intakeMotor.move(102);
			}else if(rightTriggerDown){
				intakeMotor.move(-102);
			}else{
				intakeMotor.move(0);
			}
			//Dont hog!
			pros::delay(2);
		}//end infinite loop
}//end opcontrol
