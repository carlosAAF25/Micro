// Definición de pines
const int ledParpadeo = 13;
const int ledBoton = 10;
const int pinBoton = 2;

// Variables para el parpadeo (millis)
unsigned long tiempoAnterior = 0;
const long intervalo = 500; // Tiempo en ms para el parpadeo
int estadoLed13 = LOW;

void setup() {
  pinMode(ledParpadeo, OUTPUT);
  pinMode(ledBoton, OUTPUT);
  
  // Usamos PULLUP interno para ahorrar una resistencia física
  // El botón debe conectar el pin 2 con tierra (GND)
  pinMode(pinBoton, INPUT_PULLUP); 
}

void loop() {
  // --- TAREA 1: PARPADEO DEL PIN 13 (Sin delay) ---
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual; // Guardamos el tiempo actual
    // Cambiamos el estado del LED
    if (estadoLed13 == LOW) {
      estadoLed13 = HIGH;
    } else {
      estadoLed13 = LOW;
    }
    digitalWrite(ledParpadeo, estadoLed13);
  }

  // --- TAREA 2: CONTROL DEL PIN 10 CON PULSADOR ---
  // Al usar INPUT_PULLUP, el pin lee LOW cuando se presiona
  int lecturaBoton = digitalRead(pinBoton);

  if (lecturaBoton == LOW) {
    digitalWrite(ledBoton, HIGH);
  } else {
    digitalWrite(ledBoton, LOW);
  }
}..elimina  los comentarios