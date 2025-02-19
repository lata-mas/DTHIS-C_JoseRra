#include <Adafruit_MAX31865.h>

// Usamos software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10, 11, 12, 13);
// Para hardware SPI solo se pasa el pin CS
// Adafruit_MAX31865 thermo = Adafruit_MAX31865(10);

// Valor del resistor de referencia. Usa 430.0 para PT100 y 4300.0 para PT1000
#define RREF      4300.0
// Resistencia nominal a 0°C del sensor:
// 100.0 para PT100, 1000.0 para PT1000
#define RNOMINAL  1000.0

void setup() {
  // Inicializa el MAX31865 (elige 2WIRE o 4WIRE según corresponda)
  thermo.begin(MAX31865_2WIRE);
}

// Función que realiza la medición y retorna la temperatura radiante en grados Celsius.
float RadiantTemp() {
  // Lectura del valor RTD
  uint16_t rtd = thermo.readRTD();
  
  // Calcula la razón y la resistencia (opcional si se requiere para otros cálculos)
  float ratio = rtd;
  ratio /= 32768.0;
  float resistance = RREF * ratio;
  
  // Calcula la temperatura utilizando el método de la librería
  float radiant = thermo.temperature(RNOMINAL, RREF);
  return radiant;
}
