#include <AFMotor.h>    // incluye la librería AFMotor
                        // include AFMotor library

AF_DCMotor motor(4);    // crea un objeto motor en el puerto 4
                        // create a motor object on port 4

void setup() {
  Serial.begin(9600);   // inicializa la librería Serial a 9600 bps
                        // set up Serial library at 9600 bps
  Serial.println("Motor test!"); // imprime "Motor test!" en el monitor serial
                                 // print "Motor test!" to the serial monitor

  motor.setSpeed(200);  // establece la velocidad del motor a 200
                        // set the motor speed to 200
  
  motor.run(RELEASE);   // libera el motor
                        // turn off the motor
}

void loop() {
  uint8_t i;
  
  Serial.print("tick"); // imprime "tick" en el monitor serial
                        // print "tick" to the serial monitor
  
  motor.run(FORWARD);   // hace que el motor gire hacia adelante
                        // make the motor run forward
  for (i = 0; i < 255; i++) {  // incrementa la velocidad del motor
                               // increase the motor speed
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i = 255; i != 0; i--) { // disminuye la velocidad del motor
                               // decrease the motor speed
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock"); // imprime "tock" en el monitor serial
                        // print "tock" to the serial monitor

  motor.run(BACKWARD);  // hace que el motor gire hacia atrás
                        // make the motor run backward
  for (i = 0; i < 255; i++) {  // incrementa la velocidad del motor
                               // increase the motor speed
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i = 255; i != 0; i--) { // disminuye la velocidad del motor
                               // decrease the motor speed
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tech"); // imprime "tech" en el monitor serial
                        // print "tech" to the serial monitor
  motor.run(RELEASE);   // libera el motor
                        // turn off the motor
  delay(1000);          // espera 1 segundo
                        // wait 1 second
}
