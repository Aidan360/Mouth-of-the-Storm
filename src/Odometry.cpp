#include "autonFunctions.hpp"
    void odom::odomThread() {
        double lastPosition[4]; // x,y then left and right rotations in inches
        double lastHeading; // last Theta value
        double gearRatio = 0.6;
        double motorLeftAvg;
        double motorRightAvg;
        double deltaLeft;
        double deltaRight;
        double distLeft;
        double distRight;
        double deltaAngle;
        float distanceOffset;    
        double orientationAvg = 0;
        pros::c::imu_set_heading(IMUPort, position[2]); // 180 for first auton, 225 for second one.  135 for skills
        pros::c::motor_tare_position(motorPortLeft[0]);
        pros::c::motor_tare_position(motorPortRight[0]);
        pros::c::motor_tare_position(motorPortLeft[1]);
        pros::c::motor_tare_position(motorPortRight[1]);
        pros::c::motor_tare_position(motorPortLeft[2]);
        pros::c::motor_tare_position(motorPortRight[2]);
     //   distToNextPoint =  sqrt(pow(injectionPoints[lastPointIndex + 1][0] - position[0],2) + pow(injectionPoints[lastPointIndex + 1][1] - position[0],2));



        double linearError; 
        double linearLastError; 
        double linearIntegral;
        double linearDerivative;
        float linearOutput;
        int linearIntError = sgn(linearError);
        float heading;
        double rotationalError;
        double rotationalLastError;
        double rotationalIntegral;
        double rotationalDerivative;
        float rotationalOutput;
        int rotationalIntError = sgn(rotationalError);

        pros::delay(1000);
        double cartToPolarR;
        double cartToPolarθ;
        while (true) {
        /* Odometry */
        motorLeftAvg =  (pros::c::motor_get_position(motorPortLeft[1])+pros::c::motor_get_position(motorPortLeft[0]))/2*gearRatio;
        motorRightAvg =  (pros::c::motor_get_position(motorPortRight[1])+pros::c::motor_get_position(motorPortRight[0]))/2*gearRatio;
        deltaLeft = (motorLeftAvg - lastPosition[2]);
        deltaRight = (motorRightAvg - lastPosition[3]);
        distLeft = degRad(deltaLeft) * (wheelSize/2);
        distRight = degRad(deltaRight) * (wheelSize/2);  

        heading = heading + ((distLeft - distRight)/trackLength)*-1; 
       //heading = int(pros::c::imu_get_heading(IMU_PORT)*10000000)*0.0000001;
        deltaAngle = heading - lastHeading;
        if(deltaAngle < 0.1) {
            if (distRight == 0) { 
            distanceOffset = distRight;
            }
            else {
                distanceOffset = distLeft;
            }
        }
        else {

            if (distRight == 0) { 
                distanceOffset = 2*sin(heading/2) * (distRight/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
            }
            else {
                distanceOffset = 2*sin(heading/2) * (distLeft/deltaAngle + (trackLength/2)); // this is the distance travelled, it will be added to "distance" which is purely a PID variable that does not matter whatsoever. 
            }    
        }
        orientationAvg = lastHeading + deltaAngle/2;
        cartToPolarR = distanceOffset;  
        cartToPolarθ = 0; 
        position[0] = cartToPolarR*cos(cartToPolarθ-orientationAvg)+position[0];
        position[1] = cartToPolarR*sin(cartToPolarθ-orientationAvg)*-1+position[1];

        
        lastPosition[0] = position[0]; 
        lastPosition[1] = position[1];
        lastPosition[2] = motorLeftAvg;
        lastPosition[3] = motorRightAvg;
        lastHeading = heading;
        position[2] = pros::c::imu_get_heading(IMUPort); 
}
    }