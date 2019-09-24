boolean automatic = true;  //Establecemos una variable boleana como verdadera

void Run() 
{
  
  if(automatic){ //Establecemos un condicional dependiente de la variable en caso de ser verdadera

     if (Output == Setpoint) //Establecemos una condicion de distancia para los motores
     {
     //Enviamos una accion de freno a los motores
     motor1.brake();  
     motor2.brake();
     }
     
     if (Output >= 0) //Establecemos la contraparte a la condicion de la distancia a los motores
     {
      //Enviamos una accion de arranque a los motores
      motor1.drive(Output,100);
      motor2.drive(-Output,100);
     }

     if (Output <= 0) //Establecemos la contraparte a la condicion de la distancia a los motores
     {
      //Enviamos una accion de arranque a los motores
      motor1.drive(Output,100);
      motor2.drive(-Output,100);
     }
  }
  
}
