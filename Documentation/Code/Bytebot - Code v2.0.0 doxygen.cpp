/**
 * @file ByteBot.cpp
 * @brief Código de control para el robot ByteBot del equipo ByteBots.
 * 
 * Este código controla el movimiento de un robot utilizando un motor DC y un servo. 
 * El robot ajusta su velocidad y dirección en función de la distancia medida por un sensor ultrasónico.
 * 
 * @authors Anthony Vargas
 * @authors Yonathan González
 * @version 1.0
 * @date 2024
 */

// Incluye las librerías necesarias
#include <Wire.h>
#include <Servo.h>
#include <AFMotor.h>

/** @brief Pin de conexión del servo motor */
const int pinServo = 9;

/** @brief Posición central del servo motor */
const int posCentro = 80;

/** @brief Posición del servo motor al girar */
const int posGiro = 100;

/** @brief Posición del servo motor para retroceso */
const int posRetroceso = 50;

/** @brief Pin Trigger del sensor ultrasónico */
const int triggerPin = 17;

/** @brief Pin Echo del sensor ultrasónico */
const int echoPin = 18;

/** @brief Velocidad inicial del motor */
int velocidadMotor = 170;

/** @brief Incremento de la velocidad del motor */
const int velocidadIncremento = 10;

/** @brief Velocidad máxima del motor */
const int velocidadMaxima = 200;

/** @brief Velocidad mínima del motor */
const int velocidadMinima = 150;

/** @brief Distancia umbral en cm para hacer el giro */
const int distanciaUmbral = 70;

/** @brief Distancia en cm para activar el retroceso */
const int distanciaRetroceso = 35;

// Instancia del motor conectado al puerto M1
AF_DCMotor motor1(1);

// Instancia del objeto Servo
Servo servo;

/**
 * @brief Configuración inicial del sistema.
 * 
 * Configura los pines de entrada/salida, inicializa la comunicación serial e I2C, 
 * y establece la posición inicial del servo y la velocidad del motor.
 */
void setup() {
    Serial.begin(115200);          // Inicializa la comunicación serie a 115200 baudios
    Wire.begin();                  // Inicializa la comunicación I2C

    servo.attach(pinServo);        // Conecta el servo al pin definido
    servo.write(posCentro);        // Inicializa el servo en la posición central
    motor1.setSpeed(velocidadMotor); // Establece la velocidad inicial del motor

    pinMode(triggerPin, OUTPUT);   // Configura el pin del trigger como salida
    pinMode(echoPin, INPUT);       // Configura el pin del echo como entrada
}

/**
 * @brief Función principal del sistema.
 * 
 * Lee la distancia desde el sensor ultrasónico y ajusta la velocidad y dirección 
 * del motor y la posición del servo en consecuencia.
 */
void loop() {
    long duracion, distancia;

    // Realiza una medición con el sensor ultrasónico
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    duracion = pulseIn(echoPin, HIGH);
    distancia = (duracion / 2) / 29.1; // Convierte la duración a distancia en cm

    // Muestra la distancia en el monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Ajusta la velocidad del motor según la distancia
    if (distancia <= distanciaRetroceso) {
        // Retrocede si el objeto está a 35 cm o menos
        servo.write(posRetroceso); // Gira el servo a la posición de retroceso
        motor1.setSpeed(velocidadMotor); // Mantiene la velocidad actual
        motor1.run(BACKWARD); // Retrocede el motor
        delay(1000); // Mantiene el retroceso durante 1 segundo
        motor1.run(RELEASE); // Detiene el motor
        servo.write(posCentro); // Regresa el servo a la posición central
        delay(500); // Espera medio segundo para estabilizar el servo
        return; // Salta el resto del loop
    } else if (distancia < distanciaUmbral) {
        // Reduce la velocidad si el objeto está a menos de 70 cm
        velocidadMotor -= velocidadIncremento;
        if (velocidadMotor < velocidadMinima) velocidadMotor = velocidadMinima; // Asegura que la velocidad no sea menor que la mínima
        motor1.setSpeed(velocidadMotor); // Actualiza la velocidad del motor
    } else {
        // Aumenta la velocidad si el objeto está a más de 70 cm
        velocidadMotor += velocidadIncremento;
        if (velocidadMotor > velocidadMaxima) velocidadMotor = velocidadMaxima; // Limita la velocidad a la máxima
        motor1.setSpeed(velocidadMotor); // Actualiza la velocidad del motor
    }

    motor1.run(FORWARD); // Avanza el motor

    // Realiza el giro si la distancia es menor a 70 cm
    if (distancia < distanciaUmbral) {
        servo.write(posGiro); // Gira el servo a la posición de giro
        delay(2000); // Mantiene el giro durante 2 segundos
        servo.write(posCentro); // Regresa el servo a la posición central
        delay(1000); // Espera 1 segundo para estabilizar el servo
    }

    delay(100); // Espera un momento antes de la próxima solicitud
}
