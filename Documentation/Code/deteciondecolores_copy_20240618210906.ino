#include <Servo.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

Servo myservo;  // Crea un objeto servo para controlar un servo

int servoPin = 9;  // Pin donde está conectado el servo
int leftPos = 65;  // Posición izquierda del servo
int centerPos = 70;  // Posición centrada del servo

// Define los pines para la HuskyLens
SoftwareSerial mySerial(10, 11);  // RX, TX
HUSKYLENS huskyLens;  // Crea un objeto HuskyLens

void setup() {
  myservo.attach(servoPin);  // Conecta el servo al pin especificado
  Serial.begin(9600);  // Inicializa la comunicación serial
  mySerial.begin(9600);  // Inicializa la comunicación serial con HuskyLens

  // Inicializa la HuskyLens con SoftwareSerial
  if (!huskyLens.begin(mySerial)) {
    Serial.println("Failed to initialize HuskyLens");
    while (1);
  }
  Serial.println("HuskyLens initialized");

  // Configura el algoritmo de detección de colores en la HuskyLens
  huskyLens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
}

void loop() {
  if (huskyLens.request()) {
    if (huskyLens.isLearned()) {
      HUSKYLENSResult result = huskyLens.read();
      
      // Verifica si el ID detectado es 1 o 2
      if (result.ID == 1) {
        moverServo(leftPos);  // Mueve el servo a la posición izquierda
        // Espera hasta que se detecte el ID 2
        while (true) {
          if (huskyLens.request()) {
            HUSKYLENSResult newResult = huskyLens.read();
            if (newResult.ID == 2) {
              moverServo(centerPos);  // Mueve el servo a la posición centrada
              break;  // Sale del bucle
            }
          }
          delay(100);  // Pequeña espera entre cada lectura
        }
      }
    } else {
      Serial.println("No color learned.");
    }
  } else {
    Serial.println("Request failed.");
  }

  delay(100);  // Pequeña espera entre cada lectura
}

void moverServo(int pos) {
  myservo.write(pos);  // Mueve el servo a la posición especificada
  delay(500);  // Espera para que el servo alcance la posición
  verificarCentro();  // Verifica si el servo está centrado
}

void verificarCentro() {
  int currentPos = myservo.read();  // Lee la posición actual del servo
  if (currentPos >= 69 && currentPos <= 71) {
    Serial.println("El servo está centrado.");
  } else {
    Serial.print("El servo no está centrado. Posición actual: ");
    Serial.println(currentPos);
  }
}
