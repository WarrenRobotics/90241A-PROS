#include "main.h"

//Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);
//Motors
pros::Motor driveLFMotor(DRIVE_LEFT_FRONT_PORT);
pros::Motor driveLBMotor(DRIVE_LEFT_BACK_PORT);
pros::Motor driveRFMotor(DRIVE_RIGHT_FRONT_PORT, true);
pros::Motor driveRBMotor(DRIVE_RIGHT_BACK_PORT, true);
pros::Motor fwUpperMotor(FLYWHEEL_UPPER_PORT);
pros::Motor fwLowerMotor(FLYWHEEL_LOWER_PORT, true);
pros::Motor intakeMotor(INTAKE_PORT);

/*-----------Autonomous Movement Functions--------------*/
/**
  * Drives the bot in a specified direction for a certain distance. The
  * power of the motors is defined as well as if the function should wait
  * for the motors to stop before exiting.
  *
  * @param reverse direction for which way is considered forwards
  * @param rev distance robot should go in revolutions
  * @param vel velocity for motors to travel at(depends on gearsets)
  * @param waitForComplete if the function should wait for the motors to stop
  *        spinning
  */
void driveFor(bool reverse, double rev, int vel, bool waitForComplete){
  //Get target encoder ticks(arugment to function is in revolutions)
  double distance = rev/900;
  //Set proper reversal
  if(reverse){
    driveLFMotor.set_reversed(true);
    driveLBMotor.set_reversed(true);
    driveRFMotor.set_reversed(false);
    driveRBMotor.set_reversed(false);
  }
  //Set drive to target
  driveLFMotor.move_relative(distance, vel);
  driveLBMotor.move_relative(distance, vel);
  driveRFMotor.move_relative(distance, vel);
  driveRBMotor.move_relative(distance, vel);
  if(waitForComplete){
    //Loop until at least one motor stops
    while(!(driveLFMotor.is_stopped() || driveLBMotor.is_stopped() || driveRFMotor.is_stopped() || driveRBMotor.is_stopped())){
      pros::delay(2);
    }
  }
  //Reset motors to original revering
  driveLFMotor.set_reversed(false);
  driveLBMotor.set_reversed(false);
  driveRFMotor.set_reversed(true);
  driveRBMotor.set_reversed(true);
}
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

  //RedFlag Park
  if(autonomousMode == 1){

  }
  //RedFlag NoPark
  if(autonomousMode == 2){

  }
  if(autonomousMode == 3){

  }
  if(autonomousMode == 4){

  }
  if(autonomousMode == 5){

  }
  if(autonomousMode == 6){

  }
  if(autonomousMode == 7){

  }
  if(autonomousMode == 8){

  }
}
