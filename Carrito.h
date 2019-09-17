//// Librerias
//
////#include "Ultrasonido.h"
//#include <SparkFun_TB6612.h>
//
//// Config pines y variables
//
//#define AIN1 9
//#define BIN1 8
//#define AIN2 10
//#define BIN2 7
//#define PWMA 5
//#define PWMB 6
//#define STBY -1
//
//const int offsetA = 1;
//const int offsetB = 1;
//
//// Initializing motors.
//
//Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
//Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

boolean automatic = true;

void Run()

{
  if(automatic){
    //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.


   if (distancia <= 20)
   {
   motor1.brake();
   motor2.brake();
//   motor1.drive(-255,100);
//   motor2.drive(255,100);
//   Medir();
   }
   else
   {    motor1.drive(255,100);
        motor2.drive(-255,100);
    }
}
}
