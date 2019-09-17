//// Librerias
//
//#include <SparkFun_TB6612.h>
//
//// Config pines y variables
//
//String inputString = "";         // a String to hold incoming data
//bool stringComplete = false;  // whether the string is complete
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

void RunMan()

{

  // reserve 200 bytes for the inputString:
   inputString.reserve(200);
    
    //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    

  if (inputString.startsWith("For"))

    {
        motor1.drive(255,100);
        motor2.drive(-255,100);
    }

  if (inputString.startsWith("Brake"))

    {
        motor1.brake();
        motor2.brake();
    }

  if (inputString.startsWith("Back"))

    {
        motor1.drive(-255, 100);
        motor2.drive(255, 100);
    }

  if (inputString.startsWith("Aut"))

    {
        automatic = true;
    }

      if (inputString.startsWith("Man"))

    {
        automatic = false;
    }

      inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
