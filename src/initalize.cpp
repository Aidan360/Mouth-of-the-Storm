#include "autonFunctions.hpp"
#include "initalize.hpp"
#include "pros/optical.hpp"
std::vector<int> motorPortLeft;
std::vector<int> motorPortRight;

void initialize() {
	// initializers
    pros::lcd::initialize();
    pros::Motor leftFrontMotor_initializer (leftFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftMiddleMotor_initializer (leftMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);  
    pros::Motor leftBackMotor_initializer (leftBackMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightFrontMotor_initializer (rightFrontMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightMiddleMotor_initializer (rightMiddleMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES); 
    pros::Motor rightBackMotor_initializer (rightBackMotor_PORT, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor intake_initializer (intake_PORT,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);  
    pros::Motor wallMech_initializer (wallMech_PORT,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES); 
    // declarations

    pros::Motor leftFrontMotor (leftFrontMotor_PORT);
    pros::Motor leftMiddleMotor (leftMiddleMotor_PORT);
    pros::Motor leftBackMotor (leftBackMotor_PORT);
    pros::Motor rightFrontMotor (rightFrontMotor_PORT);
    pros::Motor rightMiddleMotor (rightMiddleMotor_PORT);
    pros::Motor rightBackMotor (rightBackMotor_PORT);
    pros::Motor intake(intake_PORT);
    pros::Motor wallMech(wallMech_PORT);
    pros::Optical color(color_PORT);

    /*  leftFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      leftMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      leftBackMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightFrontMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
      rightMiddleMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);  */

    PIDC dt;
    dt.rpm = 450;
    motorPortLeft.push_back(leftFrontMotor_PORT);
    motorPortLeft.push_back(leftMiddleMotor_PORT);
    motorPortLeft.push_back(leftBackMotor_PORT);
    motorPortRight.push_back(rightFrontMotor_PORT);
    motorPortRight.push_back(rightMiddleMotor_PORT);
    motorPortRight.push_back(rightBackMotor_PORT); 
        pros::c::imu_reset_blocking(imu_PORT);
}
