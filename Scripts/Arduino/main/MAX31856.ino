#include <PWFusion_MAX31856.h>

// Pines para los termopares
uint8_t tcChipSelects[] = {10, 9, 8, 7};  
MAX31856 thermocouples[4];  

/**
 * Función: ThermocoupleMeasurements
 * 
 * Lee y calibra las temperaturas de cuatro termopares tipo T.
 * 
 * Retorno:
 * - Puntero a un array de cuatro floats con las temperaturas calibradas.
 */
float* ThermocoupleMeasurements() {
  static float temperatures[4];  
  static bool initialized = false;

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

    // Aplica la calibración correspondiente
    if (i == 0) {
      temperatures[i] = 1.0452 * rawTemperature + -3.3077;  // Pin 10
    } else if (i == 1) {
      temperatures[i] = 1.0483 * rawTemperature + -3.0385;  // Pin 9
    } else if (i == 2) {
      temperatures[i] = 1.0292 * rawTemperature + -1.8033;  // Pin 8
    } else if (i == 3) {
      temperatures[i] = 1.0437 * rawTemperature + -2.2989;  // Pin 7
    }
  }

  return temperatures;
}
