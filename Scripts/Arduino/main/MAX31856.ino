#include <PWFusion_MAX31856.h>

// Definición de pines para los termopares
uint8_t tcChipSelects[] = {9, 8, 7, 6};  

// Array de objetos MAX31856, uno para cada termopar tipo T
MAX31856 thermocouples[4];  

/**
 * Función: ThermocoupleMeasurements
 * 
 * Descripción:
 * Esta función lee las mediciones de temperatura de cuatro termopares tipo T conectados
 * a un shield PWFusion MAX31856. Devuelve un puntero a un array de cuatro posiciones 
 * que contiene las temperaturas medidas por los termopares.
 * 
 * Proceso:
 * - Inicializa los termopares la primera vez que se llama a la función.
 * - Configura los termopares para que operen con el tipo T, filtro de 60 Hz, 
 *   promedio de 4 muestras y modo de medición de un solo disparo.
 * - Inicia la medición de temperatura y espera un breve período para que la lectura
 *   se complete antes de tomar la muestra.
 * - Devuelve un puntero a un array que contiene las cuatro temperaturas medidas.
 * 
 * Retorno:
 * - Puntero a un array de cuatro floats que contienen las temperaturas medidas.
 * 
 * Notas:
 * - La inicialización de los termopares solo ocurre la primera vez que se llama a la función.
 * - Se utiliza un array estático para mantener las temperaturas entre llamadas sucesivas a la función.
 */
float* ThermocoupleMeasurements() {
  // Array estático para almacenar las temperaturas de los cuatro termopares
  static float temperatures[4];  

  // Variable para controlar la inicialización de los termopares
  static bool initialized = false;

  // Inicialización de los termopares solo una vez
  if (!initialized) {
    // Configuración de cada termopar
    for (int i = 0; i < 4; i++) {
      thermocouples[i].begin(tcChipSelects[i]);  // Inicializa el termopar con el pin correspondiente
      // Configura el termopar: tipo T, filtro de 60 Hz, promedio de 4 muestras, modo de medición de un solo disparo
      thermocouples[i].config(T_TYPE, CUTOFF_60HZ, AVG_SEL_4SAMP, CMODE_OFF);
    }
    initialized = true;  // Marca como inicializado para evitar reconfiguración
  }

  // Lectura de las temperaturas de cada termopar
  for (int i = 0; i < 4; i++) {
    thermocouples[i].startOneShotMeasurement();  // Inicia la medición de temperatura
    delay(180);  // Espera el tiempo necesario para que la medición se complete
    thermocouples[i].sample();  // Lee la muestra de temperatura
    temperatures[i] = thermocouples[i].getTemperature();  // Almacena la temperatura leída
  }

  // Retorna un puntero al array de temperaturas
  return temperatures;
}
