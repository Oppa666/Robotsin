#include <PID_v1.h>
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

double kp = 100;
double ki = 50;
double kd = 15; 

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,kp,ki,kd,P_ON_E, DIRECT); //P_ON_M specifies that Proportional on Measurement be used
                                                            //P_ON_E (Proportional on Error) is the default behavior
void TareaPid()
{
  /*  
 *   Si esta en modo manual se debe ingresar a este programa y con los valores de las ganancias
 *   de las constantes proporcional kp integral ki y derivativo kd
 *   realiza el calculo y lo escribe en la salida PWM de la planta
 */
    Input= distancia;
    myPID.Compute();
    Serial.print(" ");
    Serial.print(Setpoint);
    Serial.print(" ");
    Serial.println(Input);
    Serial.print(" ");
    Serial.println(Output);

}

void  SetupPid()
  {
  //initialize the variables we're linked to
  Input = distancia;
  Setpoint = 15;

  //turn the PID on
    myPID.SetTunings(kp,ki,kd);
    myPID.SetControllerDirection(DIRECT);
    myPID.SetSampleTime(100);
    myPID.SetOutputLimits(-255,255);
//    myPID.Initialize();  
    myPID.SetMode(AUTOMATIC);  
  }
