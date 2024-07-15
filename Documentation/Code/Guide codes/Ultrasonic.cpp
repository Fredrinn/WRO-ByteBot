// Este código realiza la medición de distancia usando un sensor ultrasónico.
// This code performs distance measurement using an ultrasonic sensor.

int TRIG = 10;         // Pin 10 usado para el trigger del sensor
                      // Pin 10 used for the sensor's trigger
int ECO = 9;           // Pin 9 usado para el echo del sensor
                      // Pin 9 used for the sensor's echo
int LED = 3;           // Pin 3 usado para controlar un LED indicador
                      // Pin 3 used to control an indicator LED
int DURACION;          // Variable para almacenar la duración del pulso de eco
                      // Variable to store the duration of the echo pulse
int DISTANCIA;         // Variable para almacenar la distancia calculada en centímetros
                      // Variable to store the calculated distance in centimeters

void setup()
{
  pinMode(TRIG, OUTPUT);   // Configura el pin TRIG como salida
                          // Set TRIG pin as output
  pinMode(ECO, INPUT);     // Configura el pin ECO como entrada
                          // Set ECO pin as input
  pinMode(LED, OUTPUT);    // Configura el pin LED como salida
                          // Set LED pin as output
  Serial.begin(9600);      // Inicializa la comunicación serial a 9600 bps
                          // Initialize serial communication at 9600 bps
}

void loop()
{
  digitalWrite(TRIG, HIGH);        // Genera un pulso alto en el pin TRIG
                                  // Generate a high pulse on TRIG pin
  delay(1);                        // Espera un breve momento
                                  // Wait for a short moment
  digitalWrite(TRIG, LOW);         // Apaga el pulso del sensor
                                  // Turn off the sensor pulse
  
  DURACION = pulseIn(ECO, HIGH);   // Mide la duración del pulso de eco en ECO
                                  // Measure the duration of the echo pulse on ECO
                                  // El pulso es esperado en estado alto
                                  // Pulse is expected to be high
  
  DISTANCIA = DURACION / 58.2;     // Calcula la distancia en centímetros
                                  // Calculate the distance in centimeters
  Serial.println(DISTANCIA);       // Envía la distancia medida al monitor serial
                                  // Send the measured distance to the serial monitor
  delay(200);                      // Espera antes de la próxima medición
                                  // Wait before the next measurement
}
