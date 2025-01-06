#include "main.h"
#include "autonFunctions.hpp"
#include "pros/rtos.hpp"
PIDC dt;
	
void autonomous() { 
    pros::ADIDigitalOut goalMech (goalMech_PORT);
    pros::Motor wallMech(wallMech_PORT); 
    pros::Motor intake(intake_PORT);
    dt.fP = 15;
    dt.fI = 0.025;
    dt.fD = 0.05;
    dt.forwardTolerence = 10;
    dt.turnTolerence = 1;
    dt.tP = 70; 
    dt.tI = 0.0015;
    dt.tD = 0.275;
    pros::c::imu_reset_blocking(imu_PORT);
    pros::c::imu_set_heading(imu_PORT, 170);
/*    dt.move(-36);
    goalMech.set_value(true);
    dt.move(12);
    intake.move_velocity(400); */
   
   
   /* dt.move(12);
    pros::delay(500);
    dt.move(12);
    pros::delay(500);
    dt.move(-24);
    pros::delay(500);
    dt.move(24);
    pros::delay(500);
    dt.move(-12);
    pros::delay(500);
    dt.move(-12);
    pros::delay(500);
    dt.move(6);
    pros::delay(500);
    dt.move(18);
    pros::delay(500);
    dt.move(-6);
    pros::delay(500);
    dt.move(-18);
    pros::delay(500); */
    
 /*   dt.turn(90);
    pros::delay(250);
    dt.turn(180);
    pros::delay(250);
    dt.turn(270);
    pros::delay(250);
    dt.turn(90);
    pros::delay(250);
    dt.turn(270);
    pros::delay(250);
    dt.turn(225);
    pros::delay(250);
    dt.turn(180);
    pros::delay(250);
    dt.turn(135);
    pros::delay(250);
    dt.turn(90);
    pros::delay(250);
    dt.turn(225);
    pros::delay(250);
    dt.turn(270);
    pros::delay(250);
    dt.turn(135);
    pros::delay(250);
    dt.turn(90);
    pros::delay(250); */
    
    //    dt.turn(270);
    //    pros::delay(500);
    //    dt.turn(90);
/*
    dt.move(8);
    wallMech.move(127);
    pros::delay(1000);
    wallMech.move(-127); 
    
    // wall mech slam 
   dt.move(-13);
    dt.move(13);
    wallMech.move(0);
    dt.move(-13);
    dt.move(13);
    */
  /*  dt.turn(90);  // works
    dt.move(32);
    //intake move 150
    intake.move_velocity(400);
    dt.move(10);
    dt.turn(180);
    intake.move(0); 
    
    dt.move(26);
    //intake move 100
    intake.move_velocity(200);
    dt.turn(90);
    intake.move_velocity(0);
    dt.move(-16);
    goalMech.set_value(true);
    intake.move_velocity(400);
    dt.turn(45);
    dt.move(-24);  */
    //goalMech.set_value(false);
    //pros::delay(500); 
    //dt.turn(180+60);'

    // Skills ?? 
  /*   dt.move(8);
    wallMech.move(127);
    pros::delay(1000);
    wallMech.move(-127); 
    
    // wall mech slam 
    dt.move(-13);
    dt.move(13);
    wallMech.move(0);
    dt.move(-13);
    dt.move(18);
    dt.turn(260);
    dt.move(-20);
    goalMech.set_value(true);
    dt.turn(80);
    intake.move_velocity(400);
    dt.move(36);
    dt.turn(170);
    dt.move(-48);
    intake.move_velocity(0);
    goalMech.set_value(false);
    
    dt.turn(260);
    intake.move(150);
    dt.move(18);
    intake.move(0);
    dt.move(54);
    dt.turn(350);
    dt.move(-12);
    goalMech.set_value(true);
    intake.move_velocity(400);
    dt.move(12);
    dt.turn(260);
    dt.move(18);
    dt.turn(170);
    dt.move(-16);
    goalMech.set_value(false);
    
    wallMech.move(127);
    pros::delay(1000);
    wallMech.move(0);
    dt.turn(125);
    dt.move(60); */
    //dt.move(144);
    //dt.move(-6);
//    dt.turn(260);



}