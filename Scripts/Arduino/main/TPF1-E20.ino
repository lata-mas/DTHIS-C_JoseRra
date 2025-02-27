#include <Adafruit_MAX31865.h>

// Usamos software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10, 11, 12, 13);
// Para hardware SPI solo se pasa el pin CS
// Adafruit_MAX31865 thermo = Adafruit_MAX31865(10);

#define RREF      4300.0  // Resistor de referencia (usa 430.0 para PT100 o 4300.0 para PT1000)
#define RNOMINAL  1000.0  // Resistencia nominal a 0°C (100.0 para PT100, 1000.0 para PT1000)

// Función que realiza la medición y retorna la temperatura radiante en grados Celsius.
float TPF1Temp() {
  // Inicializa el sensor solo la primera vez que se llama a la función.
  static bool initialized = false;
  if (!initialized) {
    thermo.begin(MAX31865_2WIRE);  // Inicialización del MAX31865
    initialized = true;
  }
  
  // Lectura del valor RTD
  uint16_t rtd = thermo.readRTD();
  
  // Calcula la razón y la resistencia (opcional si se requiere para otros cálculos)
  float ratio = rtd / 32768.0;
  float resistance = RREF * ratio;
  
  // Calcula la temperatura utilizando el método de la librería
  float raw_temp = thermo.temperature(RNOMINAL, RREF);

  // Aplica la ecuación de calibración: 1.0582 * temp + (-1.5553)
  float radiant_temp = 1.0582 * raw_temp - 1.5553;
  
  return radiant_temp;
}
