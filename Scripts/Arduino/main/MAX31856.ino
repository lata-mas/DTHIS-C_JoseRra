#include <PWFusion_MAX31856.h>

// Pines para los termopares
const uint8_t tcChipSelects[] = {10, 9, 8, 7};
MAX31856 thermocouples[4];

/**
 * Función: ThermocoupleMeasurements
 * Lee y calibra las temperaturas de cuatro termopares tipo T.
 * 
 * Retorno:
 * - Puntero a un array de cuatro floats con las temperaturas calibradas.
 */
float* ThermocoupleMeasurements() {
  static float temperatures[4];  
  static bool initialized = false;

  // Coeficientes de calibración
  const float m[4] = {1.0460, 1.0600, 1.0801, 1.0547};  // Pendientes
  const float b[4] = {-2.5241, -2.8834, -4.4269, -3.9315};  // Intersecciones

  // Inicialización de los termopares solo la primera vez
  if (!initialized) {
    for (int i = 0; i < 4; i++) {
      thermocouples[i].begin(tcChipSelects[i]);
      thermocouples[i].config(T_TYPE, CUTOFF_60HZ, AVG_SEL_4SAMP, CMODE_OFF);
    }
    initialized = true;
  }

  // Lectura y calibración de las temperaturas
  for (int i = 0; i < 4; i++) {
    thermocouples[i].startOneShotMeasurement();
    delay(180);
    thermocouples[i].sample();
    float rawTemperature = thermocouples[i].getTemperature();
    temperatures[i] = m[i] * rawTemperature + b[i];  // Aplica la calibración
  }

  return temperatures;
}
