void RunMan()

{

  // reserve 200 bytes for the inputString:
   inputString.reserve(200);
    
  //Establecems la condicion para el SerialEvent
  if (stringComplete) {
    Serial.println(inputString);
    
// A continuacion estan todos los comandos que son reconocidos en el Serial Event
// con sus respectivas acciones
    if (inputString.startsWith("Back"))
  
      {
          motor1.drive(255,100);
          motor2.drive(-255,100);
      }
  
    if (inputString.startsWith("Brake"))
  
      {
          motor1.brake();
          motor2.brake();
      }
  
    if (inputString.startsWith("For"))
  
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

//Final del Serial Event
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
