#include "display/lv_objx/lv_ta.h"
#include "main.h"
#include "autonFunctions.hpp"
#include "pros/rtos.hpp"
PIDC dt;
	
void autonomous() { 
    pros::ADIDigitalOut goalMech (goalMech_PORT);
    pros::Motor wallMech(wallMech_PORT); 
      pros::ADIDigitalOut climb(clawRelease_PORT); 
    pros::Motor intake(intake_PORT);
    dt.fP = 15;
    dt.fI = 0.035;
    dt.fD = 0.05;
    dt.forwardTolerence = 10;
    dt.turnTolerence = 1;
    dt.tP = 80; 
    dt.tI = 0.01;
    dt.tD = 0.5;

//skills  
/*
pros::c::imu_set_heading(imu_PORT, 170);
dt.move(-18);
goalMech.set_value(true);
dt.turn(260);
intake.move(127);
dt.move(40);
dt.turn(350);
dt.move(-18);
goalMech.set_value(false);
dt.move(18); */
                                                                 // RED 
    // GOAL RUSH 
    
    pros::c::imu_set_heading(imu_PORT, 80);
      dt.move(9);
      dt.turn(170);
      dt.move(10);
      wallMech.move_absolute(500, 200);
      pros::delay(1000);
      wallMech.move_absolute(0,200);
        pros::delay(1000); 
      /*
      dt.move(-14);
      pros::delay(500);
      dt.turn(130);
  dt.move(-20);  */ //move back to grab goal  
/* revised ring rush*/
/*
pros::c::imu_set_heading(imu_PORT, 80);
  drive(9,200);
  turn(170);
  drive(10,200);
  wallMech.move_absolute(-500, 200);
  pros::delay(1000);
  wallMech.move_absolute(0,200);
  pros::delay(1000);
  drive(-14,300);
  turn(130);
  drive(-20,450); 
  goalMech.set_value(true);
  pros::delay(500);
  turn(260);
  intake.move(127);
  drive(26,200);
  pros::delay(250);
  drive(-6,200);
  turn(80);
  drive(36,450); */


  /*
    pros::delay(250); 
    goalMech.set_value(true); // grab goal 
         pros::delay(250); 
    dt.turn(260); // turn towards ring 
    intake.move(127); 
    dt.move(26); 
    pros::delay(250); 
    dt.move(-6);
    dt.turn(80);
    dt.move(36);  */   
    // GOAL RUSH  

    


                                                              // BLUE
          // RING RUSH 
   
   /*   pros::c::imu_set_heading(imu_PORT, 235);
      dt.move(8);

      wallMech.move_absolute(-270, 100);
      pros::delay(250);
      dt.move(-20);
      dt.turn(190);
  dt.move(-24); // move back to grab goal 
    pros::delay(250); 
    goalMech.set_value(true); // grab goal 
         pros::delay(250); 
    dt.turn(100); // turn towards ring 
    intake.move(127); 
    dt.move(26); 
    pros::delay(250); 
    dt.move(-6);
    dt.turn(280);
    dt.move(36); */


    /* 
    dt.turn(10); 
    dt.move(14);
    pros::delay(500);
    dt.move(-6);
    dt.turn(145+15);
    dt.move(38);
    climb.set_value(true);
    dt.turn(10);
    */

    
 /*   dt.turn(10+45);
    dt.move(6);
    pros::delay(250); 
    dt.move(-6); 
    pros::delay(500);    
    intake.move(0);  */
/*    dt.move(-36);
    goalMech.set_value(true);
    dt.move(12);
    intake.move_velocity(400); */
   
   /*
    dt.move(12);
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
    
  /*
  pros::c::imu_set_heading(imu_PORT, 180);
  dt.turn(90);
    pros::delay(500);
    dt.turn(180);
    pros::delay(500);
    dt.turn(270);
    pros::delay(500);
    dt.turn(90);
    pros::delay(500);
    dt.turn(270);
    pros::delay(500);
    dt.turn(225);
    pros::delay(500);
    dt.turn(180);
    pros::delay(500);
    dt.turn(135);
    pros::delay(500);
    dt.turn(90);
    pros::delay(500);
    dt.turn(225);
    pros::delay(500);
    dt.turn(270);
    pros::delay(500);
    dt.turn(135);
    pros::delay(500);
    dt.turn(90);
    pros::delay(500);  */
    
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