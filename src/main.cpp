#include "main.h"
#include "initalize.hpp"
#include "pros/adi.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
 	pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Motor intake(intake_PORT);
    pros::Motor wallMech(wallMech_PORT);
	pros::ADIDigitalOut goalMech (goalMech_PORT);
	pros::ADIDigitalOut climb (clawRelease_PORT);
	pros::ADIDigitalIn intakeSensor(intakeSensor_PORT);
	pros::Optical color(color_PORT);
void disabled() {}


void competition_initialize() {}

	bool goal = false;
	bool climbR = false;
	int colorCool = 500; 
	int colorCount = 0;
	int reverseDelay = 1250;
	int reverseDelayCount = 0;

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {
		float power = -master.get_analog(ANALOG_RIGHT_X)*0.7;
		float turn = -master.get_analog(ANALOG_LEFT_Y);
		float left = pow(power + turn,3) *0.0001;
		float right = pow(power - turn,3) *0.0001;
		leftFrontMotor.move(right); // Conners Move
		leftMiddleMotor.move(right);
		leftBackMotor.move(right);
		rightFrontMotor.move(left);
		rightMiddleMotor.move(left);
		rightBackMotor.move(left);
		wallMech.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		//wallMech.move(DIGITAL_R2);
		//wallMech.move(DIGITAL_R1);

		//intake.move(DIGITAL_L1*127);
		if (master.get_digital_new_press(DIGITAL_RIGHT)) { 
			if(goal == false) {  // if the piston is false 
				goalMech.set_value(true); // sets piston to true
				goal = true; // robot knows it is true 
			}
			else {
				goalMech.set_value(false); // retracts piston
				goal = false; // robot knows its false
			}
		}
		if (master.get_digital_new_press(DIGITAL_B)) {
			if(climbR == false) {
				climb.set_value(true);
				climbR = true;
			}
			else {
				climb.set_value(false);
				climbR = false; 
			}
		}
		if (master.get_digital(DIGITAL_L1)) {
			intake.move_velocity(600);
		}
		else if ((master.get_digital(DIGITAL_DOWN))) {
			if (( (color.get_hue() > 55) || (color.get_hue() < 30) )) { // blue is above 55, red is below 30
				intake.move_velocity(250); // it detects the ring and keeps on going because it is not at the ideal reverse area 
				colorCount = colorCool; 
				reverseDelayCount = reverseDelay;
			}

			else if(colorCount > 0) { 
				intake.move_velocity(250); // contiunes going until it reaches the top 
				colorCount = colorCount - 10; // color count acts as a wait before it reverses
			}
			else if(reverseDelayCount > 0){
				intake.move_velocity(-250); // begins reversing 
				reverseDelayCount = reverseDelayCount - 10; // reversal cooldown
			}
			else {
				intake.move_velocity(250); // nothing is detected but slows for ring detection.
			}
	
			
		
		}
		else {
			intake.move_velocity(0);
		}
		if (master.get_digital(DIGITAL_L2)) {
			intake.move_velocity(-600);
		}
		if (master.get_digital(DIGITAL_R1)) {
			wallMech.move(127);
		}
		else if (master.get_digital(DIGITAL_R2)) {
			wallMech.move(-127);
		}
		else {
			wallMech.move(0);
		}
		pros::lcd::print(0, "color: %f\n",color.get_hue());
		//if (intakeSensor.get_value() == false) { 
		//	intake.move(DIGITAL_L2*127);
		//} 
		//else {
	//		intake.move(DIGITAL_L2*-127);
//		}
		//intake.move(-DIGITAL_RIGHT*127);


		pros::delay(5);
	}
}
