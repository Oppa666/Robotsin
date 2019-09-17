//VARIABLES

const int pinecho = A5;
const int pintrigger = A4;
const int pinled = 13;

// VARIABLES PARA CALCULOS
unsigned int tiempo;
float distancia;


void setupDist()
{
     // CONFIGURAR PINES DE ENTRADA Y SALIDA
   pinMode(pinecho, INPUT);
   pinMode(pintrigger, OUTPUT);
   pinMode(13, OUTPUT);
  }



void Medir()
{

 // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = (float)tiempo / 58.0;
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(distancia);
  Serial.println(" cm");

  
}
