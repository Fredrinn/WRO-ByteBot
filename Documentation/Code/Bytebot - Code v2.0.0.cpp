/*
   Código del robot ByteBot del equipo ByteBots.

   Autores: Anthony Vargas - Yonathan González.
   ________________________________________________________

   ByteBot robot code by team ByteBots.

   Authors: Anthony Vargas - Yonathan Gonzalez.
*/

//Libraries are included - Se incluyen las liberías.
  #include <HUSKYLENS.h>                // Library for interacting with the HUSKYLENS sensor - Librería para interactuar con el sensor HUSKYLENS
  #include <HuskyLensProtocolCore.h>    //  Core communication protocol for HUSKYLENS - Núcleo del protocolo de comunicación para HUSKYLENS
  #include <Wire.h>                     // Library for I2C communication - Librería para comunicación I2C
  #include <Servo.h>                    // Library for controlling servomotors - Librería para controlar servomotores
  #include <AFMotor.h>                  // Library for controlling motors with Adafruit Motor Shield -  Librería para controlar motores con Adafruit Motor Shield
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

//The different objects and variables are created - Se crean los diferentes objetos y variables.

  HUSKYLENS huskylens;            // HUSKYLENS object for interacting with the sensor - Objeto HUSKYLENS para interactuar con el sensor.
  Servo servo;                    // Servo object for controlling a servo motor - Objeto Servo para controlar un servo motor.

  AF_DCMotor motor1(1);           // Motor connected to port M1 - Motor conectado al puerto M1.

  const int trigPin = 9;
  const int echoPin = 10;

//The different positions of the servomotor are declared - Se declaran las diferentes posiciones del servomotor.

  const int pinServo = 9;         // Pin donde está conectado el servo - Pin where the servo is connected
  const int posCentro = 80;       // Posición central del servo - Center position of the servo
  const int posDerecha = 50;      // Posición a la derecha del servo - Position to the right of the servo
  const int posIzquierda = 110;   // Posición a la izquierda del servo - Position to the left of the servo

//Various variables are defined to store data - Se definen varias variables para almacenar datos.
  int ultrasonicInitialValue = 0;
  int ultimaPosicionServo = posCentro; // Guarda la última posición del servo
  int contadorGiros = 0; // Contador de giros

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

// Initializes the void Setup to configure the initial parameters. - Se inicia el void Setup para configurar los parámetros iniciales.

void setup() {
    Serial.begin(115200);         // Initialize the communication series - Inicializa la comunicación serie
    Wire.begin();                 // Initializes I2C communication - Inicializa la comunicación I2C

    servo.attach(pinServo);       // Conecta el servo al pin 9
    servo.write(posCentro);       // Inicializa el servo en la posición central

    motor1.setSpeed(255); // Sets the motor speed to 255 (maximum value) - Establece la velocidad del motor a 255 (valor máximo)
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

// Intenta inicializar HuskyLens utilizando la comunicación I2C.
    while (!huskylens.begin(Wire)) {
      Serial.println(F("¡Fallo al iniciar HuskyLens!"));
      delay(500); // Wait 0.5 second before trying again - Espera 0.5 segundo antes de intentar nuevamente
    }
    Serial.println(F("¡HuskyLens inicializado!"));         // HuskyLens initialized successfully - ¡HuskyLens inicializado correctamente!
    huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION); // Selects the color recognition algorithm - Selecciona el algoritmo de reconocimiento de colores
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void loop() {
    if (!huskylens.request()) {
        Serial.println(F("Fallo al solicitar datos de HUSKYLENS, ¡verifique la conexión!"));
    } else if (!huskylens.available()) {
        servo.write(posCentro); // No hay datos disponibles, mantener en posición central
        ultimaPosicionServo = posCentro; // Actualiza la última posición del servo
        contadorGiros = 0; // Reinicia el contador de giros
    } else {
        while (huskylens.available()) {
            HUSKYLENSResult result = huskylens.read();
            if (result.command == COMMAND_RETURN_BLOCK) {
                if (result.ID == 1 || result.ID == 3) {
                    servo.write(posDerecha); // Detecta ID 1 o ID 3, mueve a la posición derecha
                    ultimaPosicionServo = posDerecha;
                    contadorGiros = 13; // Establece el contador de giros a 13
                    delay(2500); // Espera 2500 ms
                } else if ((result.ID == 2 || result.ID == 4) && contadorGiros <= 0) {
                    servo.write(posIzquierda); // Detecta ID 2 o ID 4, mueve a la posición izquierda solo si no se detectó ID 1 o ID 3 primero
                    ultimaPosicionServo = posIzquierda;
                    delay(2500); // Espera 2500 ms
                }
            }
        }
    }
    servo.write(ultimaPosicionServo); // Mantener la última posición del servo
    motor1.run(FORWARD); // Continúa avanzando

    if (contadorGiros > 0) {
        contadorGiros--; // Disminuye el contador de giros en cada ciclo
    }

    delay(100); // Espera un momento antes de la próxima solicitud
}

//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
void printResult(HUSKYLENSResult result) {
    if (result.command == COMMAND_RETURN_BLOCK) {
        Serial.println(String() + F("Bloque: xCentro=") + result.xCenter + F(", yCentro=") + result.yCenter + F(", ancho=") + result.width + F(", alto=") + result.height + F(", ID=") + result.ID);
    } else if (result.command == COMMAND_RETURN_ARROW) {
        Serial.println(String() + F("Flecha: xOrigen=") + result.xOrigin + F(", yOrigen=") + result.yOrigin + F(", xDestino=") + result.xTarget + F(", yDestino=") + result.yTarget + F(", ID=") + result.ID);
    } else {
        Serial.println("¡Objeto desconocido!");
    }
}

void ultrasonicBegin (){
  long duration1, duration2, duration3;
  float distance, averageDistance = 0;
  int validReadings = 0;
  
  // Primer pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration1 = pulseIn(echoPin, HIGH, 30); // Máximo de 30ms
  
  // Segundo pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration2 = pulseIn(echoPin, HIGH, 30); // Máximo de 30ms
  
  // Tercer pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration3 = pulseIn(echoPin, HIGH, 30); // Máximo de 30ms
  
  // Calcular la distancia promedio omitiendo lecturas inválidas (0)
  if (duration1 > 0) {
    distance += duration1 * 0.034 / 2;
    validReadings++;
  }
  if (duration2 > 0) {
    distance += duration2 * 0.034 / 2;
    validReadings++;
  }
  if (duration3 > 0) {
    distance += duration3 * 0.034 / 2;
    validReadings++;
  }
  
  if (validReadings > 0) {
    averageDistance = distance / validReadings;
  } else {
    Serial.println("No se detectaron lecturas válidas.");
  }
  
  Serial.print("Distancia promedio: ");
  Serial.print(averageDistance);
  Serial.println(" cm");
  
  delay(150);  // Espera 500 ms antes de la siguiente medición
}
