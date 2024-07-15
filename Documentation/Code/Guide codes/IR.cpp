int SENSOR = 2;         // salida de KY-033 a pin digital 2
                        // output of KY-033 to digital pin 2
int VALOR;              // almacena valor leido del sensor
                        // stores the read value from the sensor
int ANTERIOR = 1;       // almacena ultimo valor leido del sensor
                        // stores the last read value from the sensor

void setup(){
  Serial.begin(9600);   // inicializa comunicacion serie a 9600 bps
                        // initialize serial communication at 9600 bps
  pinMode(SENSOR, INPUT);  // pin 2 como entrada
                            // pin 2 as input
}

void loop(){
  VALOR = digitalRead(SENSOR);  // lee valor de sensor y asigna a variable VALOR
                                // read sensor value and assign to VALOR variable
  if (VALOR != ANTERIOR){   // si el valor es distinto del ultimo
                            // if the value is different from the last one
    if (VALOR == HIGH)      // si VALOR tiene un nivel alto es linea negra
                            // if VALOR is high it means it's on the black line
      Serial.println("Linea"); // imprime en monitor serial la palabra Linea
                               // print "Linea" to serial monitor
    else                    // si VALOR tiene un nivel bajo es fuera de linea
                            // if VALOR is low it means it's off the black line
      Serial.println("Fuera"); // imprime en monitor serial la palabra Fuera
                               // print "Fuera" to serial monitor
    ANTERIOR = VALOR;       // actualiza variable ANTERIOR con el actual de VALOR
                            // update ANTERIOR variable with current VALOR
  }
  delay(500);             // breve demora de medio segundo
                          // short delay of half a second
}
