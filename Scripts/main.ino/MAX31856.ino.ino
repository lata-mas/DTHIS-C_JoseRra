#include <PWFusion_MAX31856.h>

// Definición de pines para los termopares
// Estos pines se utilizan para seleccionar el chip MAX31856 en el bus SPI.
uint8_t tcChipSelects[] = {9, 8};  

// Array de objetos MAX31856, uno para cada termopar tipo T
MAX31856 thermocouples[2]; 

// Función para obtener las mediciones de temperatura de los termopares
float* ThermocoupleMeasurements() {
  // Array estático para almacenar las temperaturas de los dos termopares
  static float temperatures[2];  

  // Variable para controlar la inicialización de los termopares
  static bool initialized = false;

  // Inicialización de los termopares solo una vez
  if (!initialized) {
    // Configuración de cada termopar
    for (int i = 0; i < 2; i++) {
      thermocouples[i].begin(tcChipSelects[i]);  // Inicializa el termopar con el pin correspondiente
      // Configura el termopar: tipo T, filtro de 60 Hz, promedio de 4 muestras, modo de medición de un solo disparo
      thermocouples[i].config(T_TYPE, CUTOFF_60HZ, AVG_SEL_4SAMP, CMODE_OFF);
    }
    initialized = true;  // Marca como inicializado para evitar reconfiguración
  }

  // Lectura de las temperaturas de cada termopar
  for (int i = 0; i < 2; i++) {
    thermocouples[i].startOneShotMeasurement();  // Inicia la medición de temperatura
    delay(180);  // Espera el tiempo necesario para que la medición se complete
    thermocouples[i].sample();  // Lee la muestra de temperatura
    temperatures[i] = thermocouples[i].getTemperature();  // Almacena la temperatura leída
  }

  // Retorna un puntero al array de temperaturas
  return temperatures;
}
