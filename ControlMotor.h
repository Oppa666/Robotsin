// Librerias

#include <SparkFun_TB6612.h>

// Config pines y variables

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

#define AIN1 9
#define BIN1 8
#define AIN2 10
#define BIN2 7
#define PWMA 5
#define PWMB 6
#define STBY -1

const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
