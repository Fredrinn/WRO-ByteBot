#include <Servo.h>        // incluye libreria de Servo
                          // include Servo library

Servo servo1;             // crea objeto
                          // create object

int PINSERVO = 2;         // pin 2 conectado a señal del servo
                          // pin 2 connected to servo signal
int PULSOMIN = 1000;      // pulso minimo en microsegundos
                          // minimum pulse in microseconds
int PULSOMAX = 2000;      // pulso maximo en microsegundos
                          // maximum pulse in microseconds
int VALORPOT;             // variable para almacenar valor leido en entrada A0
                          // variable to store value read on A0 input
int ANGULO;               // valor de angulo a cargar en el servo
                          // angle value to send to the servo

int POT = 0;              // potenciometro en entrada analogica A0
                          // potentiometer on analog input A0

void setup()
{
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);  // inicializacion de servo
                                                // servo initialization
  // las entradas analogicas no requieren inicializacion
  // analog inputs do not require initialization
}

void loop()
{
  VALORPOT = analogRead(POT);            // lee valor de entrada A0
                                         // read value from A0 input
  ANGULO = map(VALORPOT, 0, 1023, 0, 180); // con funcion map convierte rango de 0 a 1023
                                         // a rango de angulo de 0 a 180
                                         // using map function converts range from 0 to 1023
                                         // to angle range from 0 to 180
  servo1.write(ANGULO);                  // envia al servo el valor del angulo
                                         // send angle value to the servo
  delay(20);                             // demora para que el servo llegue a posicion
                                         // delay for the servo to reach position
}
