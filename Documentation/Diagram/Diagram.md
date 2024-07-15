# Technical Description of System Diagram

## Main Components

1. **Arduino Mega 2560 Board**:
   - Located at the center of the diagram.
   - Provides control and logic for the system.
   - Key connections:
     - Powered by batteries.
     - Sensors and actuators connected to various pins.

   ![Arduino Mega](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/Arduino-mega.jpg){:height="250px"}

2. **L298N Motor Driver Module**:
   - Positioned to the left of the Arduino board.
   - Controls the DC motor and servo.
   - Key connections:
     - Powered and controlled by Arduino.
     - Outputs to DC motor and servo.

   ![L298N Motor Driver](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/l293d-arduino-motor-driver-shield.jpg){:height="250px"}

3. **18650 Batteries**:
   - Two batteries located on the left, connected in series to provide power.
   - Connection to motor driver and Arduino board.

   ![18650 Batteries](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/18650-battery-3000mah.jpg){:height="250px"}

4. **HC-SR04 Ultrasonic Sensor**:
   - Located in the bottom right of the diagram.
   - Used for measuring distances to objects in front of the system.
   - Connections to Arduino digital pins for trigger and echo.

   ![HC-SR04 Ultrasonic Sensor](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/HC-SR04.jpg){:height="250px"}

5. **IR Sensor Module**:
   - Positioned just left of the ultrasonic sensor.
   - Used for detecting nearby obstacles.
   - Connections to Arduino digital pins.

   ![IR Sensor](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/sensor-infrarrojo.jpg){:height="250px"}

6. **Camera Module**:
   - Located in the top right of the diagram.
   - Connected to the Arduino board for image capture.
   - Power and communication connected through specific pins.

   ![Camera Module](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/HuskyLens.png){:height="250px"}

## Detailed Connections

- **Power**:
  - 18650 batteries are connected in series, providing power to both the L298N motor driver and the Arduino Mega board.
  - Red cables indicate positive voltage connections (+), and black cables indicate ground connections (-).

- **Motor Control**:
  - The L298N module receives control signals from the Arduino board to manage the DC motor and servo.
  - The DC motor is connected to the outputs of the L298N for speed and direction control.
  - The servo motor is also connected to the L298N for position control.

- **Sensors**:
  - The HC-SR04 ultrasonic sensor connects to Arduino digital pins for trigger and echo functionality.
  - The IR sensor module is connected to digital pins for obstacle detection.

- **Communication and Additional Sensors**:
  - The camera module is connected to the Arduino board via specific pins for communication and power.

## Operational Technical Description

The system is designed to function as an autonomous mobile robot. The Arduino Mega board acts as the brain of the system, controlling the movement of the DC motor and servo motor through the L298N module. The 18650 batteries provide the necessary power for the entire system.

The HC-SR04 ultrasonic sensor and IR module are used for obstacle detection, allowing the Arduino to receive data about object proximity and adjust motor direction accordingly to avoid collisions.

The camera module adds vision capabilities to the system, enabling the capture of images or videos that can be processed for navigation or object recognition.

---

# Descripción Técnica del Diagrama del Sistema

## Componentes Principales

1. **Placa Arduino Mega 2560**:
   - Ubicada en el centro del diagrama.
   - Proporciona el control y la lógica para el sistema.
   - Conexiones principales:
     - Alimentación desde baterías.
     - Sensores y actuadores conectados a varios pines.

   ![Arduino Mega](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/Arduino-mega.jpg =250x)

2. **Módulo Driver de Motores L298N**:
   - Ubicado a la izquierda de la placa Arduino.
   - Controla el motor de corriente continua (DC motor) y el servo.
   - Conexiones principales:
     - Alimentación y control desde Arduino.
     - Salidas a motor DC y servo.

   ![L298N Motor Driver](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/l293d-arduino-motor-driver-shield.jpg =250x)

3. **Baterías 18650**:
   - Dos baterías ubicadas a la izquierda, conectadas en serie para proporcionar alimentación.
   - Conexión al driver de motores y a la placa Arduino.

   ![Baterías 18650](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/18650-battery-3000mah.jpg =250x)

4. **Sensor Ultrasónico HC-SR04**:
   - Ubicado en la parte inferior derecha del diagrama.
   - Utilizado para medir la distancia de objetos delante del sistema.
   - Conexiones a pines digitales en Arduino para trigger y echo.

   ![Sensor Ultrasónico HC-SR04](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/HC-SR04.jpg =250x)

5. **Módulo Sensor IR (Infrarrojo)**:
   - Ubicado justo a la izquierda del sensor ultrasónico.
   - Utilizado para la detección de obstáculos cercanos.
   - Conexiones a pines digitales en Arduino.

   ![Sensor IR](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/sensor-infrarrojo.jpg =250x)

6. **Módulo Cámara**:
   - Ubicado en la parte superior derecha del diagrama.
   - Conectado a la placa Arduino para la captura de imágenes.
   - Alimentación y comunicación conectadas a través de pines específicos.

   ![Módulo Cámara](https://github.com/Fredrinn/WRO-ByteBot/blob/main/Documentation/Diagram/Component/HuskyLens.png =250x)

## Conexiones Detalladas

- **Alimentación**:
  - Las baterías 18650 están conectadas en serie y alimentan tanto el driver de motores L298N como la placa Arduino Mega.
  - Los cables rojos indican conexiones de voltaje positivo (+) y los cables negros indican conexiones a tierra (-).

- **Control de Motores**:
  - El módulo L298N recibe señales de control desde la placa Arduino para manejar el motor DC y el servo.
  - El motor DC está conectado a las salidas del L298N, permitiendo su control de velocidad y dirección.
  - El servo motor también está conectado al L298N para control de posición.

- **Sensores**:
  - El sensor ultrasónico HC-SR04 tiene conexiones a los pines digitales del Arduino para los pines de trigger y echo.
  - El módulo sensor IR está conectado a pines digitales para detección de obstáculos.

- **Comunicación y Sensores Adicionales**:
  - El módulo cámara está conectado a la placa Arduino mediante pines específicos para comunicación y alimentación.

## Descripción Técnica del Funcionamiento

El sistema está diseñado para funcionar como un robot móvil autónomo. La placa Arduino Mega actúa como el cerebro del sistema, controlando el movimiento del motor DC y el servo motor a través del módulo L298N. Las baterías 18650 proporcionan la energía necesaria para todo el sistema.

El sensor ultrasónico HC-SR04 y el módulo IR se utilizan para la detección de obstáculos, permitiendo que el Arduino reciba datos sobre la proximidad de objetos y ajuste la dirección del motor en consecuencia para evitar colisiones.

La cámara añade capacidades de visión al sistema, permitiendo la captura de imágenes o videos que pueden ser procesados para navegación o reconocimiento de objetos.
