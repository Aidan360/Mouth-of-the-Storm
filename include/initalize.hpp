#include "main.h"
#define leftFrontMotor_PORT 1 // Speed 
#define leftMiddleMotor_PORT 2 // Speed
#define leftBackMotor_PORT 3 // Speed
#define rightFrontMotor_PORT 4 // Speed
#define rightMiddleMotor_PORT 5 // Speed
#define rightBackMotor_PORT 6 // Speed
#define intake_PORT 7 // Torque
#define wallMech_PORT 8 // Torque 
#define expander_PORT 11 // extender for other sensors
#define imu_PORT 11 // Port for Temporary IMU 
#define color_PORT 20 // Color sensor 

#define pto_PORT 'a'
#define clawRelease_PORT 'b'
#define goalMech_PORT 'a'
#define intakeSensor_PORT 'd'

extern double sgn(double x);
extern double abso(double x);
extern double degRad(double x);
extern double radDeg(double x);


extern std::vector<int> motorPortLeft;
extern std::vector<int> motorPortRight;