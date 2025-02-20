#include <math.h>

const int OutPin  = A0;   // Pin analógico para el sensor de viento ("OUT")
const int TempPin = A2;   // Pin analógico para el sensor de temperatura ("TMP")

// Función que lee ambos sensores y retorna un array de dos floats:
// result[0] -> velocidad de viento (m/s)
// result[1] -> temperatura (°C)
float* getWindAndTemp() {
  static float result[2];
  
  // Lectura del sensor de viento
  int windADunits = analogRead(OutPin);
  float voltage = (float)windADunits * 5.0 / 1024.0;
  
  // Aplicar la corrección al voltaje
  float correctedVoltage = voltage - 1.1621;
  
  // Lectura del sensor de temperatura
  int tempRawAD = analogRead(TempPin);
  float tempC = ((((float)tempRawAD * 5.0) / 1024.0) - 0.400) / 0.0195;
  
  // Cálculo de la velocidad de viento en m/s usando la ecuación empírica:
  // WS = 26.3431 * (correctedVoltage)^(1.4273) * (tempC)^(-0.7631)
  float windSpeed = 26.3431 * pow(correctedVoltage, 1.4273) * pow(tempC, -0.7631);
  
  result[0] = windSpeed;
  result[1] = tempC;
  
  return result;
}
