# Documentación del Proyecto Bytebots

## <img src="https://raw.githubusercontent.com/0xAbdulKhalid/0xAbdulKhalid/main/assets/mdImages/about_me.gif" alt="C++" width="45" height="45"> Tecnologías Utilizadas

Este proyecto está desarrollado utilizando las siguientes tecnologías y plataformas:

<span>
    <img src="https://github.com/tandpfun/skill-icons/blob/main/icons/CPP.svg" alt="C++" width="45" height="45">
    <img src="https://github.com/tandpfun/skill-icons/blob/main/icons/Arduino.svg" alt="Arduino" width="45" height="45">
</span>

![Descripción de la imagen](https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif)

## Descripción

Este proyecto utiliza un motor servo y un sensor de visión AI HuskyLens para detectar colores y mover el servo según los IDs de color detectados. El proyecto involucra los siguientes componentes:

- **Motor Servo**: Controlado mediante la biblioteca `Servo.h` para moverse a posiciones específicas.
- **HuskyLens**: Un sensor de visión AI que utiliza la biblioteca `HUSKYLENS.h` para la detección y reconocimiento de colores.
- **SoftwareSerial**: Utilizado para comunicar con el HuskyLens mediante comunicación serial.

## <img src="https://camo.githubusercontent.com/94b33bd991f6c3135af747bdf27361be43e797c0fce678b62ed5aef57e9d8bd7/68747470733a2f2f6d65646961322e67697068792e636f6d2f6d656469612f51737347456d706b79454f684243623765312f67697068792e6769663f6369643d656366303565343761306e336769316266716e74716d6f62386739616964316f796a327772336473336d67373030626c267269643d67697068792e676966" alt="C++" width="20" height="20"> Funcionalidad

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
