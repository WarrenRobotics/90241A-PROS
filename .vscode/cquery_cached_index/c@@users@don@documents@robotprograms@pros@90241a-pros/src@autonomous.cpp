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

  //TODO: Remove me
  int autonomousMode;
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
      //Back up a little bit
      driveFor(false, 0.3, 140, true);
      //Delay so bot can turn accruately
      pros::delay(100);
      //Turn right 90 degrees to face alliance park
      turnRight(true, 1, 160, true);
      //Drive onto alliance park
      driveFor(true, 1.5, 200, true);
  }
  //RedFlag NoPark
  if(autonomousMode == 2){
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
      //Back up a little bit
      driveFor(false, 1.5, 140, true);
      //Turn left 45 degrees to face middle flag
      turnLeft(true, 0.5, 160, true);
      //Start up flywheel
      setFlywheel(200);
      //Wait until motors are at 95% of target speed
      while(fwUpperMotor.get_actual_velocity() < 190
        || fwLowerMotor.get_actual_velocity() < 190){}
      //Intake to shoot ball
      setIntake(true, 200);
      pros::delay(800);
      //Stop intake and flywheel
      stopIntake();
      stopFlywheel();
  }
  //RedCap Park
  if(autonomousMode == 3){
    //Drive to cap(and start intake halfway there)
    driveFor(true, 3.5, 75, false);
    while(driveLFMotor.get_position() < (0.5 * driveLFMotor.get_target_position())){
      //Dont hog resources!
      pros::delay(2);
    }
    //Start intake
    setIntake(true, 100);
    //Wait unti bot gets there
    while(!(driveLFMotor.is_stopped() || driveLBMotor.is_stopped() || driveRFMotor.is_stopped() || driveRBMotor.is_stopped())){
      //Don't hog resources!
      pros::delay(2);
    }
    //Stop intake
    stopIntake();
    //Drive back to line up with alliance park
    driveFor(false, 0.6, 75, true);
    //Delay to minimize effect of momentum when turning
    pros::delay(100);
    //Turn left to face alliance park
    turnLeft(true, 1, 170, true);
    //Drive onto platform
    driveFor(true, 3.75, 200, true);
    //Delay to minimize effect of momentum when turning
    pros::delay(400);
    //Turn right to face middle flag
    turnRight(true, 0.3, 100, true);
  }
  //RedCap NoPark
  if(autonomousMode == 4){
    //Start up intake
    setIntake(true, 200);
    //Drive to cap
    driveFor(true, 3.5, 150, true);
    //Stop intake
    stopIntake();
    //Drive back to start tile
    driveFor(false, 3.5, 200, true);
    //Delay to minimize effect of momentum when turning
    pros::delay(100);
    //Set flywheel
    setFlywheel(200);
    //Turn right
    turnLeft(true, 0.65, 100, true);
    //Wait until either flywheel motor is spinning at 80% velocity
    while(fwLowerMotor.get_actual_velocity() < (0.7 * 200)
        || fwUpperMotor.get_actual_velocity() < (0.7 *200)){}
    //Funnel ball into flywheel
    setIntake(true, 100);
    //Wait for ball to shoot
    pros::delay(800);
    //Stop intake and flywheel
    stopIntake();
    stopFlywheel();
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
