#include <PID_v1.h>

//Define Variables we'll be connecting to 
double Setpoint, Input, Output; 
//Establecemos los limites

//Specify the links and initial tuning parameters 
double Kp=100;
double Ki=50;
double Kd=15; 

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT); 

void setupPID() { 

 //initialize the variables we're linked to 
 Input = distancia; 
 Setpoint = 10; 
  //turn the PID on 

 myPID.SetOutputLimits(-255, 255);
 myPID.SetMode(AUTOMATIC); 
 } 
 void PIDYa() 
 { 
  Input = distancia; 
  myPID.Compute(); 
  Serial.println(distancia);
  Serial.println(Output);
      motor1.drive(Output);
      motor2.drive(Output);
 }
  
