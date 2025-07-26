#include "autonFunctions.hpp"


void CLC::move(float inch) { 
    left(inch, inch);
}
void CLC::turn(float degrees) {
    double radians = degrees* M_PI/180; 
    double distance = tan(radians)*trackLength*0.5; 
    left(-distance,distance);
}
void CLC::curve(float radius, float degree, bool reverse) { 
    double radians = degree* M_PI/180;
    if (reverse == false) { 
        left(radius*radians,(radius+trackLength)*radians); 
    } 
    else { 
        left(radius+trackLength*radians,(radius*radians)); 
    }
}





void CLC::left(float inch, float rInch){ 
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_tare_position(motorPortLeft[i]);
        pros::c::motor_tare_position(motorPortRight[i]);
    }    
    float error = 12;
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortLeft[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    float rError = (rInch/wheelSize)*180 - pros::c::motor_get_position(motorPortRight[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    float integral = 0; // 

    float derivative = 0;
    float lastError = 0;
    int intError = sgn(error); // intError
    
    float rIntegral = 0; // 
    float rDerivative = 0;
    float rLastError = 0;
    int rIntError = sgn(rError); // intError
    float count = 0;
    
    while ((abso(error) > Tolerence) && (abso(rError) > Tolerence)) {
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortLeft[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearration
    rError = (rInch/wheelSize)*180 - pros::c::motor_get_position(motorPortRight[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    pros::lcd::print(0, "Odom Value: %d\n",int((error/360)*M_PI*wheelSize*100)); // displays distance away from target
    
    integral = integral + error; // integral of pid function 
    derivative = error - lastError; // deriavative of pid function
    rIntegral = rIntegral + rError; // integral of pid function 
    rDerivative = rError - rLastError;
    double output = lP*error + lI*integral + lD*derivative + lS*sgn(error); // voltage output
    double Routput = rP*error + rI*rIntegral + rD*rDerivative + rS*sgn(rError); // voltage output
    for (int i = 0; i < std::size(motorPortLeft); ++i) { // loop for each motor 
        pros::c::motor_move_voltage(motorPortLeft[i],output); 
      pros::c::motor_move_voltage(motorPortRight[i],Routput); 
    }
    lastError = error; 
    rLastError = rError; 
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
    if (sgn(rError) != rIntError) {
        rIntegral = 0;
        rIntError = sgn(rError);
    }
    pros::delay(10);
    }  
    pros::lcd::print(1, "done %d", int((error * 2.75 / 360)*2*10));  // i'm going to be so real idk these formulas here I copy and pasted my old code
    for (int i = 0; i < std::size(motorPortLeft); ++i) {
        pros::c::motor_move_voltage(motorPortLeft[i],0);
        pros::c::motor_move_voltage(motorPortRight[i],0);
    }
} 
void CLC::right(float inch){ 
    for (int i = 0; i < std::size(motorPortRight); ++i) {
        pros::c::motor_tare_position(motorPortRight[i]);
    }    
    float error = 12;
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortRight[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    
    float integral = 0; // 
    float derivative = 0;
    float lastError = 0;
    int intError = sgn(error); // intError
    float count = 0;
    while (abso(error) > Tolerence) {
    error = (inch/wheelSize)*180 - pros::c::motor_get_position(motorPortRight[0]) * 0.75; // d/(r*pi) * 180 - encoder * gearratio
    pros::lcd::print(0, "Odom Value: %d\n",int((error/360)*M_PI*wheelSize*100)); // displays distance away from target
    
    integral = integral + error; // integral of pid function 
    derivative = error - lastError; // deriavative of pid function
    
    double output = rP*error + rI*integral + rD*derivative + rS*sgn(error); // voltage output
    for (int i = 0; i < std::size(motorPortRight); ++i) { // loop for each motor 
        pros::c::motor_move_voltage(motorPortRight[i],output);
    }
    lastError = error; 
    if (int(pros::c::motor_get_actual_velocity(motorPortRight[1])) == 0) {
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
    for (int i = 0; i < std::size(motorPortRight); ++i) {
        pros::c::motor_move_voltage(motorPortRight[i],0);
    }
} 