boolean automatic = false;  //Establecemos una variable boleana como verdadera

void Run() 
{
  
  if(automatic){ //Establecemos un condicional dependiente de la variable en caso de ser verdadera

     if (Output > 14 & Output < 16) //Establecemos una condicion de distancia para los motores
     {
     //Enviamos una accion de freno a los motores
          motor1.drive(-255, 2500);
          motor2.drive(40, 2500);
     }
     
     if (Output >= 0) //Establecemos la contraparte a la condicion de la distancia a los motores
     {
      //Enviamos una accion de arranque a los motores
      motor1.drive(Output);
      motor2.drive(-Output);
     }

     if (Output <= 0) //Establecemos la contraparte a la condicion de la distancia a los motores
     {
      //Enviamos una accion de arranque a los motores
      motor1.drive(Output);
      motor2.drive(-Output);
     }
  }
  
}
