#include <PWFusion_MAX31856.h>

// Definición de los pines chip select para cada termopar
uint8_t tcChipSelects[] = {10, 9, 8, 7};
#define NUM_THERMOCOUPLES   (sizeof(tcChipSelects) / sizeof(uint8_t))

// Coeficientes de calibración para cada termopar
const float m[4] = {1.0450, 1.0602, 1.0814, 1.0554};  // Pendientes
const float b[4] = {-2.4327, -2.8632, -4.4316, -3.9348};  // Intersecciones

// Se crea un objeto MAX31856 para cada termopar
MAX31856 thermocouples[NUM_THERMOCOUPLES];

void setup() {
  // Espera para la estabilización de los sensores
  delay(1000);
  
  // Inicializa cada sensor
  for (int i = 0; i < NUM_THERMOCOUPLES; i++) {
    thermocouples[i].begin(tcChipSelects[i]);
    thermocouples[i].config(T_TYPE, CUTOFF_60HZ, AVG_SEL_4SAMP, CMODE_OFF);
  }
}

// Función que realiza la medición y retorna un puntero a un array de floats con
// las temperaturas ambiente calibradas de cada sensor.
float* ThermocoupleTemp() {
  // Declaramos un array estático para conservar los datos tras salir de la función
  static float temperatures[NUM_THERMOCOUPLES];
  
  // Inicia la medición en cada sensor
  for (int i = 0; i < NUM_THERMOCOUPLES; i++) {
    thermocouples[i].startOneShotMeasurement();
  }
  
  // Espera el tiempo necesario para que la conversión se complete
  delay(180);
  
  // Actualiza la muestra en cada sensor
  for (int i = 0; i < NUM_THERMOCOUPLES; i++) {
    thermocouples[i].sample();
  }
  
  // Obtiene la temperatura ambiente de cada sensor y aplica la calibración
  for (int i = 0; i < NUM_THERMOCOUPLES; i++) {
    if (thermocouples[i].getStatus() != 0) {
      // Si hay algún fallo, se asigna NaN (Not a Number) como indicador de error
      temperatures[i] = NAN;
    } else {
      float raw_temperature = thermocouples[i].getColdJunctionTemperature();
      temperatures[i] = m[i] * raw_temperature + b[i];  // Aplica la calibración
    }
  }
  
  return temperatures;
}
