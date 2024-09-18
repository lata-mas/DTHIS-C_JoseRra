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
 * 
 * @return La temperatura medida en grados Celsius.
 */
float readPT1000Temperature() {
  float temperatura = thermo.temperature(RNOMINAL, RREF);

  // Verifica y muestra cualquier error del sensor
  uint8_t fault = thermo.readFault();
  if (fault) {
    if (fault & MAX31865_FAULT_HIGHTHRESH) Serial.println("Fault: High Threshold");
    if (fault & MAX31865_FAULT_LOWTHRESH) Serial.println("Fault: Low Threshold");
    if (fault & MAX31865_FAULT_REFINLOW) Serial.println("Fault: Reference In Low");
    if (fault & MAX31865_FAULT_REFINHIGH) Serial.println("Fault: Reference In High");
    if (fault & MAX31865_FAULT_RTDINLOW) Serial.println("Fault: RTD In Low");
    if (fault & MAX31865_FAULT_OVUV) Serial.println("Fault: Over/Under Voltage");
    // Limpia los errores del sensor
    thermo.clearFault();
  }

  return temperatura;
}
