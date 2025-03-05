#include "autonFunctions.hpp"

void PIDC::move(float inch){ 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }    
    float error = 12;
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortLeft[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    
    float integral = 0; // 
    float derivative = 0;
    float lastError = 0;
    int intError = sgn(error); // intError
    float count = 0;
    while (abso(error) > forwardTolerence) {
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortLeft[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    pros::lcd::print(0, "Odom Value: %d\n",int((error/360)*M_PI*wheelSize*100)); // displays distance away from target
    
    integral = integral + error; // integral of pid function 
    derivative = error - lastError; // deriavative of pid function
    
    double output = fP*error + fI*integral + fD*derivative; // voltage output
    for (int i = 0; i < std::size(motorPortLeft); ++i) { // loop for each motor 
        pros::c::motor_move_voltage(motorPortLeft[i],output); 
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }
    lastError = error; 
    if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
        count = count++;
    } 
    if (error == lastError) {
        count = count++;
    } 
    else {
        count = 0;
    } 
    if (counter < count) {    
        break;
    } 
    if (sgn(error) != intError) {
        integral = 0;
        intError = sgn(error);
    }
    pros::delay(10);
    }  
    pros::lcd::print(1, "done %d", int((error * 2.75 / 360)*2*10));  // i'm going to be so real idk these formulas here I copy and pasted my old code
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],0);
        pros::c::motor_move_voltage(motorPortRight[i],0);
    }
} 

void PIDC::turn(float degree) {
    float error = degree - pros::c::imu_get_heading(IMUPort);
    int intError = sgn(error);
    double lastError = 0;
    float output;
    float integral = 0;
    float derivative = 0;
    int count = 0; 
    while ((abso(error) > 1)) { 
    error = degree - pros::c::imu_get_heading(IMUPort);  
    pros::lcd::print(0, "Heading %f", pros::c::imu_get_heading(IMUPort));
    pros::lcd::print(3,"count %f", count);
    integral = integral + error; 
    derivative = error - lastError;
    output = tP*error + tI*integral + tD*derivative; 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],-output);
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }
    lastError = error;
    if (int(pros::c::motor_get_actual_velocity(motorPortLeft[1])) == 0) {
        count = count + 1;
    }
    else {
        count = 0;
    }  
    if (counter < count) {
       break;
    }  
    if (sgn(error) != intError) {
        integral = 0;
        intError = sgn(error);
    }
    pros::delay(10);
    }  
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],0);
        pros::c::motor_move_voltage(motorPortRight[i],0);
    }
    pros::lcd::print(1, "done %f", pros::c::imu_get_heading(IMUPort)); 

}
