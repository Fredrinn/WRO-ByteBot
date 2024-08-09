/*
   Código del robot ByteBot del equipo ByteBots.

   Autores: Anthony Vargas - Yonathan González.
   ________________________________________________________

   ByteBot robot code by team ByteBots.

   Authors: Anthony Vargas - Yonathan Gonzalez.
*/

// Se incluyen las librerías necesarias para el control de motores, servos y la comunicación I2C
#include <Wire.h>                     // Librería para comunicación I2C
#include <Servo.h>                    // Librería para controlar servomotores
#include <AFMotor.h>                  // Librería para controlar motores con Adafruit Motor Shield

// Se definen las constantes para los pines del servo y el sensor ultrasónico
const int pinServo = 9;               // Pin donde está conectado el servo
const int posCentro = 80;             // Posición central del servo, usada como referencia para avanzar en línea recta
const int posGiro = 100;              // Posición del servo para realizar giros, moviendo la dirección del robot
const int posRetroceso = 50;          // Posición del servo para retroceder, girando en dirección contraria
const int triggerPin = 17;            // Pin Trigger del sensor ultrasónico, envía pulsos ultrasónicos
const int echoPin = 18;               // Pin Echo del sensor ultrasónico, recibe los pulsos reflejados

// Se definen las variables para el control de velocidad del motor y las distancias para maniobras
int velocidadMotor = 170;             // Velocidad inicial del motor, valor base para empezar a moverse
const int velocidadIncremento = 10;   // Incremento de la velocidad del motor en cada ajuste
const int velocidadMaxima = 200;      // Velocidad máxima permitida para el motor, límite superior de velocidad
const int velocidadMinima = 150;      // Velocidad mínima permitida para el motor, límite inferior de velocidad
const int distanciaUmbral = 70;       // Distancia en cm para hacer el giro, evita colisiones
const int distanciaRetroceso = 35;    // Distancia en cm para retroceder, activa la maniobra de retroceso

// Se crean los objetos para controlar el motor y el servo
AF_DCMotor motor1(1);                 // Motor conectado al puerto M1 del Adafruit Motor Shield
Servo servo;                          // Objeto Servo para controlar el servomotor

void setup() {
    Serial.begin(115200);             // Inicializa la comunicación serie a 115200 baudios para depuración
    Wire.begin();                     // Inicializa la comunicación I2C, necesaria para el sensor HUSKYLENS y otros dispositivos I2C

    servo.attach(pinServo);           // Conecta el servo al pin definido anteriormente
    servo.write(posCentro);           // Inicializa el servo en la posición central para avanzar en línea recta
    motor1.setSpeed(velocidadMotor);  // Establece la velocidad inicial del motor, utilizando el valor predefinido

    pinMode(triggerPin, OUTPUT);      // Configura el pin del trigger como salida para enviar pulsos ultrasónicos
    pinMode(echoPin, INPUT);          // Configura el pin del echo como entrada para recibir los pulsos reflejados
}

void loop() {
    long duracion, distancia;         // Variables para almacenar la duración del pulso y la distancia calculada

    // Realiza una medición con el sensor ultrasónico, enviando un pulso y midiendo el tiempo de retorno
    digitalWrite(triggerPin, LOW);    // Asegura que el trigger esté en bajo antes de enviar el pulso
    delayMicroseconds(2);             // Espera 2 microsegundos para estabilizar la señal
    digitalWrite(triggerPin, HIGH);   // Activa el trigger para enviar un pulso ultrasónico
    delayMicroseconds(10);            // Mantiene el pulso durante 10 microsegundos
    digitalWrite(triggerPin, LOW);    // Desactiva el trigger, finalizando el pulso

    duracion = pulseIn(echoPin, HIGH); // Mide el tiempo en microsegundos que tarda en recibir el eco del pulso
    distancia = (duracion / 2) / 29.1; // Convierte la duración del pulso en distancia en centímetros

    // Muestra la distancia medida en el monitor serial para fines de depuración
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Ajusta la velocidad del motor en función de la distancia medida
    if (distancia <= distanciaRetroceso) {
        // Si el objeto está muy cerca, a 35 cm o menos, activa la maniobra de retroceso
        servo.write(posRetroceso);    // Mueve el servo a la posición de retroceso para cambiar de dirección
        motor1.setSpeed(velocidadMotor); // Mantiene la velocidad actual del motor
        motor1.run(BACKWARD);         // Invierte la dirección del motor para retroceder
        delay(1000);                  // Mantiene el retroceso durante 1 segundo
        motor1.run(RELEASE);          // Detiene el motor después del retroceso
        servo.write(posCentro);       // Regresa el servo a la posición central para preparar el avance
        delay(500);                   // Espera medio segundo para estabilizar el servo antes de continuar
        return;                       // Finaliza el ciclo actual para evitar avanzar de inmediato
    } else if (distancia < distanciaUmbral) {
        // Si el objeto está dentro del umbral de 70 cm pero no tan cerca como para retroceder
        velocidadMotor -= velocidadIncremento; // Disminuye la velocidad del motor para evitar colisiones
        if (velocidadMotor < velocidadMinima) velocidadMotor = velocidadMinima; // Limita la velocidad mínima
        motor1.setSpeed(velocidadMotor); // Actualiza la velocidad del motor con el nuevo valor reducido
    } else {
        // Si no hay objetos cercanos, aumenta la velocidad del motor para avanzar más rápido
        velocidadMotor += velocidadIncremento; // Incrementa la velocidad del motor para aprovechar la distancia libre
        if (velocidadMotor > velocidadMaxima) velocidadMotor = velocidadMaxima; // Limita la velocidad máxima
        motor1.setSpeed(velocidadMotor); // Actualiza la velocidad del motor con el nuevo valor incrementado
    }

    motor1.run(FORWARD);              // Avanza el motor hacia adelante con la velocidad ajustada

    // Realiza el giro si la distancia medida es menor que el umbral definido
    if (distancia < distanciaUmbral) {
        servo.write(posGiro);         // Gira el servo a la posición de giro para cambiar la dirección del robot
        delay(2000);                  // Mantiene el giro durante 2 segundos para completar la maniobra
        servo.write(posCentro);       // Regresa el servo a la posición central para continuar avanzando recto
        delay(1000);                  // Espera 1 segundo para estabilizar el servo después del giro
    }

    delay(100);                       // Espera un corto tiempo antes de realizar la siguiente medición de distancia
}
