#include "display/lv_objx/lv_ta.h"
#include "main.h"
#include "autonFunctions.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

/*
2 cases, 
case 1: movements less then 6 inches or less then 45 degrees 
move cap at 25% speed

case 2: movements >6 
get distance  
first 3 inches move at 25% speed
remainder move at set veocity 
final 3 inches at 25% speed 



*/


float wheelInchesToDeg(float inches) {
    float x = 360*(inches / 3.25*M_PI);
    return (x); 
}

void moveMotors(float left, float right, float deg) { 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],-left,deg);
        pros::c::motor_move_relative(motorPortRight[i],right,deg);
    }
}


void drive(float inches, float velocity) {  // inches is a vector, velocity is scalar 
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }    
    
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_relative(motorPortLeft[i],wheelInchesToDeg(inches),velocity);
        pros::c::motor_move_relative(motorPortRight[i],wheelInchesToDeg(-inches),velocity);
    }
    /*int a = sgn(inches); 
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_set_brake_mode(motorPortLeft[i],pros::E_MOTOR_BRAKE_COAST);
        pros::c::motor_move_voltage(motorPortRight[i],pros::E_MOTOR_BRAKE_COAST);
        }
    if (abso(inches) <= 6) {  
        float in = wheelInchesToDeg(inches); 
        moveMotors(1.3*125,1.3*125,in*a);
        for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],0);
        pros::c::motor_move_voltage(motorPortRight[i],0);
        }
    } */
    }/*
    else {
        float aInches = inches - 6*a; 
        moveMotors(velocity *0.25*1.3,velocity * 0.25*1.3,wheelInchesToDeg(3*a));
        moveMotors(velocity *1.3,velocity *1.3,wheelInchesToDeg(aInches));
        moveMotors(velocity *0.25*1.3,velocity * 0.25*1.3,wheelInchesToDeg(3*a));
    }
         for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_set_brake_mode(motorPortLeft[i],pros::E_MOTOR_BRAKE_BRAKE);
        pros::c::motor_move_voltage(motorPortRight[i],pros::E_MOTOR_BRAKE_BRAKE);
        } */


 void turn(float degrees) { 
    float deg = degrees - pros::c::imu_get_heading(imu_PORT);
    int a = sgn(deg);
            while(abso(pros::c::imu_get_heading(imu_PORT) - degrees) >= 1) { 
                    for (int i = 0; i < std::size(motorPortLeft); ++i) {
                        pros::c::motor_move_velocity(motorPortLeft[i],-60*1.3*a);
                        pros::c::motor_move_velocity(motorPortRight[i],-60*1.3*a);
                }
            }


 }