 #include "main.h"
#include "initalize.hpp"
#include <string>
#include <vector>
 
 
 class PIDC { 
    public:

        float rpm = 450; 
        float wheelSize = 1.75*M_PI; //radius 
        char IMUPort = imu_PORT; 
        public: 
        // tPID is turning PID values fPID is back and forward PID values
        float tP = 0; 
        float tI = 0;
        float tD = 0;
        float fP = 0;
        float fI = 0;
        float fD = 0; 
        float forwardTolerence = 0.5;
        float turnTolerence = 1;
        int counter = 50;
        void move(float inch);
        void turn(float degree);
        void turnHeading(float heading);      
    private: 
        float velVol = 600/rpm;
}; 
class odom { 
    public:
        float rpm; 
        float wheelSize; //diameter i think?? 
        float trackLength;
        public: 
        void odomThread();
        // tPID is turning PID values fPID is back and forward PID values
        float position[3]; // x,y,heading
        char IMUPort = imu_PORT; 
        void moveTo(float x, float y); 
    private: 
        float velVol = 600/rpm;
}; 
    class purePursuit { 
        public:

        float rpm = 360; 
        float wheelSize;
        float velocity;
        float trackLength;
        char IMUPort = imu_PORT; 
        public: 
        int defaultInterp;
        float tP; 
        float tI;
        float tD;
        float fP;
        float fI;
        float fD; 
        float forwardTolerence;
        float turnTolerence;
        float lookAheadRadius;
        int lastPointIndex = 0;
        float heading;
        float position[3]; // x,y,heading
        void odomThread();
        void moveTo(float x, float y, int interpPoints);
        bool trackingCheck(float x1, float x2, float y1, float y2);
        float distToNextPoint;
        void curveInterpolation();        
        private: 
        int lastPursuitIndex;
        float velVol = 600/rpm;
    }; 


extern PIDC dt;
extern void drive(float inches, float velocity); // velocity in 0-450 
extern void turn(float degrees); // velocity in 0-450, absoulute velocity 
