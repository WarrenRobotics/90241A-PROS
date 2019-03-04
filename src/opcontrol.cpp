#include "main.h"

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
		//Set initial reversing
		driveLFMotor.set_reversed(false);
		driveLBMotor.set_reversed(false);
		driveRFMotor.set_reversed(true);
		driveRBMotor.set_reversed(true);
		fwUpperMotor.set_reversed(false);
		fwLowerMotor.set_reversed(true);
		intakeMotor.set_reversed(false);
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
			//Set shortcut variables
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
			//Carlos
			if(driverMode == 0){
				//Flywheel
				if(btnX){
					flyWheelToggle = true;
				}
				if(btnY){
					flyWheelToggle = false;
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
			}
			//Rahul
			if(driverMode == 1){
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
			}
			//Sam
			if(driverMode == 2){
				//Flywheel
				if(leftTriggerUp){
					flyWheelToggle = true;
				}
				if(leftTriggerDown){
					flyWheelToggle = false;
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
			}
			//Dont hog!
			pros::delay(2);
		}//end infinite loop
}//end opcontrol
