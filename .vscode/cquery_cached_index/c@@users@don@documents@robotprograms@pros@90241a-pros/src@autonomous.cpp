#include "main.h"

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
  //Get target encoder ticks(argument to function is in revolutions)
  double distance = rev*900;
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
  //Wait to complete
  if(waitForComplete){
    //Loop until at least one motor stops
    while(!(driveLFMotor.is_stopped() || driveLBMotor.is_stopped() || driveRFMotor.is_stopped() || driveRBMotor.is_stopped())){
      //Don't hog resources!
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
 * Turns the robot left a certain distance at a certain velocity.
 * Generally, 1 revolution equls 90 degrees(for a point turn)
 *
 * @param reverse true if the intake side should be treated as front
 * @param rev distance(in revolutions) to go
 * @param vel velocity for motors to spin at
 * @param waitForComplete if the function should wait for the motors to stop
 *        spinning before the function exits
 */
void turnLeft(bool reverse, double rev, int vel, bool waitForComplete){
  //Get target encoder ticks
  double distance = rev*900;
  //Set proper reversal
  if(reverse){
    driveLFMotor.set_reversed(true);
    driveLBMotor.set_reversed(true);
    driveRFMotor.set_reversed(true);
    driveRBMotor.set_reversed(true);
  }else{
    driveLFMotor.set_reversed(false);
    driveLBMotor.set_reversed(false);
    driveRFMotor.set_reversed(false);
    driveRBMotor.set_reversed(false);
  }
  //Set drive to target
  driveLFMotor.move_relative(distance, vel);
  driveLBMotor.move_relative(distance, vel);
  driveRFMotor.move_relative(distance, vel);
  driveRBMotor.move_relative(distance, vel);
  //Wait to complete
  if(waitForComplete){
    //Loop until at least one motor stops
    while(!(driveLFMotor.is_stopped() || driveLBMotor.is_stopped() || driveRFMotor.is_stopped() || driveRBMotor.is_stopped())){
      //Don't hog resources!
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
 * Turns the robot right a certain distance at a certain velocity.
 * Generally, 1 revolution equls 90 degrees(for a point turn)
 *
 * @param reverse true if the intake side should be treated as front
 * @param rev distance(in revolutions) to go
 * @param vel velocity for motors to spin at
 * @param waitForComplete if the function should wait for the motors to stop
 *        spinning before the function exits
 */
void turnRight(bool reverse, double rev, int vel, bool waitForComplete){
  //Get target encoder ticks
  double distance = rev*900;
  //Set proper reversal
  if(reverse){
    driveLFMotor.set_reversed(false);
    driveLBMotor.set_reversed(false);
    driveRFMotor.set_reversed(false);
    driveRBMotor.set_reversed(false);
  }else{
    driveLFMotor.set_reversed(true);
    driveLBMotor.set_reversed(true);
    driveRFMotor.set_reversed(true);
    driveRBMotor.set_reversed(true);
  }
  //Set drive to target
  driveLFMotor.move_relative(distance, vel);
  driveLBMotor.move_relative(distance, vel);
  driveRFMotor.move_relative(distance, vel);
  driveRBMotor.move_relative(distance, vel);
  //Wait to complete
  if(waitForComplete){
    //Loop until at least one motor stops
    while(!(driveLFMotor.is_stopped() || driveLBMotor.is_stopped() || driveRFMotor.is_stopped() || driveRBMotor.is_stopped())){
      //Don't hog resources!
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
 * Stops the drivetrain
 */
void stopDrive(){
  driveLFMotor.move_velocity(0);
  driveLBMotor.move_velocity(0);
  driveRFMotor.move_velocity(0);
  driveRBMotor.move_velocity(0);
}

/**
 * Sets the flywheel at a certain velocity.
 *
 * Velocity range(Standard gear cartridge): 0-200
 *
 *@param vel velocity to spin at
 */
void setFlywheel(int vel){
  fwLowerMotor.move_velocity(vel);
  fwUpperMotor.move_velocity(vel);
}

/**
 * Stops the flywheel
 */
void stopFlywheel(){
  fwLowerMotor.move_velocity(0);
  fwUpperMotor.move_velocity(0);
}

/**
 * Sets the intake to intake or outake at a certain velocity.
 *
 * Velocity range(Standard gear cartridge): 0-200

 * @param reverse true if it should intake, false if it should outtake
 * @param vel velocity to spain at
 */
void setIntake(bool reverse, int vel){
  //Set reversing
  if(reverse){
    intakeMotor.set_reversed(true);
  }else{
    intakeMotor.set_reversed(false);
  }
  intakeMotor.move_velocity(vel);
}

/**
 * Stops the intake.
 */
void stopIntake(){
  intakeMotor.move_velocity(0);
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
      //Drive to toggle low flag
      driveFor(true, 4, 200, true);
      pros::delay(10);
      //Drive back to adjacenit tile
      driveFor(false, 2, 200, true);
      pros::delay(10);
      //Start up flywheel
      setFlywheel(200);
      //Wait until motors are at 95% of target speed
      while(fwUpperMotor.get_actual_velocity() < 190
        || fwLowerMotor.get_actual_velocity() < 190){}
      //Move ball to shoot
      setIntake(true, 200);
      //Wait for ball to get shot
      pros::delay(800);
      //Stop flywheel and intake
      stopFlywheel();
      stopIntake();
      //Turn bot right 90 degrees
      turnRight(true, 1, 160, true);
      //Set intake to flip cap
      setIntake(false, 200);
      //Wait for intake to reach some decent level of speed
      pros::delay(100);
      //Drive to flip cap
      driveFor(true, 2, 130, true);
      //Stop the intake
      stopIntake();
      //Turn right 90 degrees
      turnRight(true, 1, 160, true);
      //Delay so bot doesnt over/under steer
      pros::delay(100);
      //Drive to adjacent tile
      driveFor(true, 2, 160, true);
      //Delay so bot can turn more accruately
      pros::delay(50);
      //Turn left 90 degrees
      turnLeft(true, 1, 130, true);
      //Delay so bot doesn't over/under steer
      pros::delay(100);
      //Set intake to scoop ball in
      setIntake(true, 200);
      //Drive to the cap to intake ball
      driveFor(true, 1.1, 160, true);
      //Stop intake
      stopIntake();
      //Delay so bot can turn accruately
      pros::delay(100);
      //Turn right 90 degrees to face alliance park
      turnRight(true, 1, 160, true);
      //Drive onto alliance park 
      driveFor(true, 1.5, 200, true);
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
