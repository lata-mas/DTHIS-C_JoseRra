// Definición de pines analógicos para el sensor de viento y el termistor
#define analogPinForRV    1   // Pin analógico para la señal de voltaje de viento (RV)
#define analogPinForTMP   0   // Pin analógico para la señal del termistor (temperatura)

// Ajuste para corregir la velocidad del viento a cero
// Este valor se usa para ajustar la sensibilidad del cálculo de velocidad del viento.
// Un valor positivo aumenta la velocidad calculada y un valor negativo la disminuye.
const float zeroWindAdjustment =  .2; 

// Variables globales para almacenar las lecturas y cálculos
int TMP_Therm_ADunits;  // Almacena la lectura analógica del termistor (para la temperatura)
float RV_Wind_ADunits;  // Almacena la lectura analógica de la señal de voltaje del viento (RV)
float RV_Wind_Volts;    // Almacena la conversión del valor analógico de viento a voltios
unsigned long lastMillis; // Marca el tiempo de la última medición (para gestionar intervalos)
int TempCtimes100;      // Almacena la temperatura en °C multiplicada por 100
float zeroWind_ADunits; // Valor de la lectura analógica para velocidad de viento nula (cero)
float zeroWind_volts;   // Valor de voltaje para velocidad de viento nula (cero)
float WindSpeed_mps;    // Velocidad del viento en metros por segundo (m/s)
float avgWindSpeed_mps; // Velocidad promedio del viento en metros por segundo (m/s)
int measurementInterval = 200; // Intervalo entre mediciones (en milisegundos)
int deltaSamples = 10;  // Número de muestras para el promedio
float windSpeedSamples[10]; // Arreglo para almacenar las muestras de velocidad del viento

/**
 * Función: getAverageWindSpeed
 * 
 * Descripción: 
 * Esta función mide y calcula la velocidad promedio del viento en un intervalo definido. 
 * Utiliza la lectura analógica de un sensor de viento y un termistor (para la temperatura)
 * y aplica una fórmula empírica para convertir estas lecturas en velocidad del viento.
 * El promedio de las mediciones se almacena y se retorna al final.
 * 
 * Retorna: 
 * - avgWindSpeed_mps: Velocidad promedio del viento en m/s.
 */
float getAverageWindSpeed() {
  // Verifica si ha transcurrido el intervalo de tiempo necesario para la medición
  if (millis() - lastMillis > measurementInterval) {
    // Lectura de los valores analógicos
    TMP_Therm_ADunits = analogRead(analogPinForTMP); // Lectura de temperatura del termistor
    RV_Wind_ADunits = analogRead(analogPinForRV);    // Lectura del sensor de viento
    RV_Wind_Volts = (RV_Wind_ADunits *  0.0048828125); // Conversión a voltios

    // Cálculo de la temperatura en °C multiplicada por 100
    TempCtimes100 = (0.005 *((float)TMP_Therm_ADunits * (float)TMP_Therm_ADunits)) 
                    - (16.862 * (float)TMP_Therm_ADunits) + 9075.4;  

    // Cálculo del valor analógico para velocidad de viento nula
    zeroWind_ADunits = -0.0006*((float)TMP_Therm_ADunits * (float)TMP_Therm_ADunits) 
                       + 1.0727 * (float)TMP_Therm_ADunits + 47.172;  

    // Conversión de la velocidad nula a voltios
    zeroWind_volts = (zeroWind_ADunits * 0.0048828125) - zeroWindAdjustment;  

    // Cálculo de la velocidad del viento utilizando una fórmula empírica
    WindSpeed_mps = pow(((RV_Wind_Volts - zeroWind_volts) /.2300) , 2.7265) * 0.44704; 
    windSpeedSamples[deltaSamples - 1] = WindSpeed_mps;
    deltaSamples--;

    // Una vez que se toman suficientes muestras, se calcula el promedio
    if (deltaSamples == 0) {
      avgWindSpeed_mps = 0;
      for (int i = 0; i < 10; i++) {
        avgWindSpeed_mps += windSpeedSamples[i];
      }
      avgWindSpeed_mps /= 10;

      // Reiniciar el contador de muestras
      deltaSamples = 10;
      for (int i = 0; i < 10; i++) {
        windSpeedSamples[i] = 0;
      }
    }

    // Actualizar el tiempo de la última medición
    lastMillis = millis();
  }

  // Retornar la velocidad promedio del viento
  return avgWindSpeed_mps;
}