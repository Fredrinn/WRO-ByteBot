# Bytebot Project Documentation

## Description

This project utilizes a servo motor and a HuskyLens AI vision sensor to detect colors and move the servo based on the detected color IDs. The project involves the following components:

- **Servo Motor**: Controlled using the `Servo.h` library to move to specified positions.
- **HuskyLens**: An AI vision sensor that uses the `HUSKYLENS.h` library for color detection and recognition.
- **SoftwareSerial**: Used to communicate with the HuskyLens via serial communication.

## Functionality

The system operates as follows:

1. **Initialization**: 
   - The servo motor is attached to a specified pin.
   - Serial communication is initialized for both standard serial and software serial (for HuskyLens).
   - The HuskyLens is initialized and set to use the color recognition algorithm.

2. **Color Detection and Servo Control**:
   - In the main loop, the system requests data from the HuskyLens.
   - If the HuskyLens detects a learned color, it reads the result.
   - If the detected color ID is `1`, the servo is moved to the left position.
   - The system then waits for the color ID `2` to be detected to move the servo to the center position.

3. **Servo Movement and Center Verification**:
   - The `moverServo` function is used to move the servo to a specified position and verify if it is centered.
   - The `verificarCentro` function checks if the servo is within the centered position range and prints the status to the serial monitor.

---

# Documentación del Proyecto bytebot

## Descripción

Este proyecto utiliza un motor servo y un sensor de visión AI HuskyLens para detectar colores y mover el servo según los IDs de color detectados. El proyecto involucra los siguientes componentes:

- **Motor Servo**: Controlado mediante la biblioteca `Servo.h` para moverse a posiciones específicas.
- **HuskyLens**: Un sensor de visión AI que utiliza la biblioteca `HUSKYLENS.h` para la detección y reconocimiento de colores.
- **SoftwareSerial**: Utilizado para comunicar con el HuskyLens mediante comunicación serial.

## Funcionalidad

El sistema opera de la siguiente manera:

1. **Inicialización**: 
   - El motor servo se conecta a un pin especificado.
   - Se inicializa la comunicación serial tanto para el serial estándar como para el serial por software (para HuskyLens).
   - Se inicializa el HuskyLens y se configura para usar el algoritmo de reconocimiento de colores.

2. **Detección de Colores y Control del Servo**:
   - En el bucle principal, el sistema solicita datos del HuskyLens.
   - Si el HuskyLens detecta un color aprendido, lee el resultado.
   - Si el ID de color detectado es `1`, el servo se mueve a la posición izquierda.
   - El sistema luego espera a que se detecte el ID de color `2` para mover el servo a la posición centrada.

3. **Movimiento del Servo y Verificación del Centro**:
   - La función `moverServo` se usa para mover el servo a una posición especificada y verificar si está centrado.
   - La función `verificarCentro` verifica si el servo está dentro del rango de posición centrada e imprime el estado en el monitor serial.
