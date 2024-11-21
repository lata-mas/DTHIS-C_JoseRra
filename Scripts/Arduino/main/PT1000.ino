#include <Adafruit_MAX31865.h>

// Define el objeto del sensor con los pines correspondientes
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10, 11, 12, 13);

// Define las constantes para el sensor PT1000
#define RREF      4300.0
#define RNOMINAL  1000.0

/**
 * Inicializa el sensor PT1000.
 * Debe ser llamado en la función setup() del archivo principal.
 */
void initPT1000() {
  thermo.begin(MAX31865_2WIRE);  // Cambia a MAX31865_4WIRE si usas una conexión de 4 cables
}

/**
 * Lee la temperatura del sensor PT1000.
 */
float readPT1000Temperature() {
  float temperatura = thermo.temperature(RNOMINAL, RREF);
  return temperatura;
}
