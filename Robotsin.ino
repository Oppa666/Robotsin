// Planificador de tareas
// -- Librerías ------------------------------------------




#include "ControlMotor.h"
#include "Ultrasonido.h"
#include "Carrito.h"
#include "ControlLaviu.h"

// -- Variables de control de tiempo ---------------------
unsigned long int T; // Tiempo total (microsegundos)
// -- Variables de temporización de tareas ---------------

// Tarea 1: Control de servo A
#define Ts1 100 // Periodo de la tarea 1
unsigned long int ts1; // Tiempo parcial (tarea 1)
unsigned long int t01; // Tiempo de la última ejecución


// Tarea 2: Control de LED
#define Ts2 100 // Periodo de la tarea 2
unsigned long int ts2; // Tiempo parcial (tarea 2)
unsigned long int t02; // Tiempo de la última ejecució


// Tarea 3: Envio de datos serie
#define Ts3 1000 // Periodo de la tarea 3
unsigned long int ts3; // Tiempo parcial (tarea 3)
unsigned long int t03; // Tiempo de la última ejecución

void setup() {



  // PREPARAR LA COMUNICACION SERIAL
   Serial.begin(115200);
setupDist();
//setupRun();
 // Inicializacion de temporizadores de tarea
 ts1 = 0;
 t01 = 0;
  
  // Inicializacion de temporizadores de tarea
 ts2 = 0;
 t02 = 0;
  
  // Inicializacion de temporizadores de tarea
 ts3 = 0;
 t03 = 0;
  
}


void loop() {
  //Actualizar tiempo
  T = millis();
  //temporizacion tarea 1
  ts1 = T - t01;
  if (ts1 >= ts1)
  {
  Medir();
  t01 = T;
  }


  // Temporizacion tarea 2
 ts2 = T - t02;
 if (ts2 >= Ts2)
 {
   Run();
   t02 = T;
 }

  //temporizacion tarea 3
  ts3 = T - t03;
  if (ts3 >= ts3)
  {
  RunMan();
  t03 = T;
  }


 }
  
