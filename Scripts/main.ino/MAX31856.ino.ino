#include <PWFusion_MAX31856.h>

// Pines de los termopares
uint8_t tcChipSelects[] = {9, 8};  
MAX31856 thermocouples[2]; 

float* ThermocoupleMeasurements() {
  static float temperatures[2];  

  static bool initialized = false;
  if (!initialized) {
    for (int i = 0; i < 2; i++) {
      thermocouples[i].begin(tcChipSelects[i]);
      thermocouples[i].config(T_TYPE, CUTOFF_60HZ, AVG_SEL_4SAMP, CMODE_OFF);
    }
    initialized = true;
  }

  for (int i = 0; i < 2; i++) {
    thermocouples[i].startOneShotMeasurement();
    delay(180);  
    thermocouples[i].sample();
    temperatures[i] = thermocouples[i].getTemperature();
  }

  return temperatures;
}