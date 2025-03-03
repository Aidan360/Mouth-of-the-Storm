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
/*
int wallMechSetting = 0;
float wallMechLoadingDeg = 90;
float wallMechDoubleDeckerDeg = 500;

void wallMechControl() { 
	if (wallMechSetting == 0) { 
		wallMech.move_absolute((wallMechLoadingDeg), 100);
		wallMechSetting++; 
	} 
	if (wallMechSetting == 1) {
		wallMech.move_absolute((wallMechDoubleDeckerDeg), 100);
		wallMechSetting = 0; 
	} 
}


*/



void disabled() {}


void competition_initialize() {}

	bool goal = false;
	bool climbR = false;
	int colorCool = 500; 
	int colorCount = 0;
	int reverseDelay = 1250;
	int reverseDelayCount = 0;
	bool drift = false; 
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
//wallMech.tare_position();
	wallMech.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	 leftFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      leftBackMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      rightFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
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
			intake.move_velocity(-600);
		}
		else if (master.get_digital(DIGITAL_L2)){
			intake.move_velocity(600);
		}
		else {
			intake.move_velocity(0);
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
		
		
		if (master.get_digital(DIGITAL_LEFT)) {
		leftFrontMotor.move(600); // Conners Move
		leftMiddleMotor.move(600);
		leftBackMotor.move(600);
		rightFrontMotor.move(600);
		rightMiddleMotor.move(600);
		rightBackMotor.move(600);
		}
		pros::lcd::print(0, "color: %f\n",color.get_hue());
		//if (intakeSensor.get_value() == false) { 
		//	intake.move(DIGITAL_L2*127);
		//} 
		//else {
	//		intake.move(DIGITAL_L2*-127);
//		}
		//intake.move(-DIGITAL_RIGHT*127);


		pros::delay(100);
	}
	}

