#include <WiFiNINA.h>
#include <PubSubClient.h>

// Definiciones para la red WiFi y ThingsBoard
#define WIFI_AP "Totalplay-1FA6"          
#define WIFI_PASSWORD "1FA6FD39hsc5Mnh9" 
#define TOKEN "1OEilpG3goyYcWLZvuz0"
#define THINGSBOARD_SERVER "tb.ier.unam.mx"
#define MQTT_PORT 1883

// Inicialización de las librerías y objetos
WiFiClient espClient;
PubSubClient mqttClient(espClient);

/**
 * Configuración inicial del dispositivo.
 * Configura la conexión WiFi y el cliente MQTT para ThingsBoard.
 */
void setup() {
  Serial.begin(115200);  // Inicia la comunicación serial para debugging
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);  // Conexión a la red WiFi

  // Espera hasta que la conexión WiFi sea exitosa
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  // Configuración del servidor MQTT
  mqttClient.setServer(THINGSBOARD_SERVER, MQTT_PORT);
  connectToThingsBoard();  // Conecta a ThingsBoard

  // Inicializa el sensor PT1000
  initPT1000();
}

/**
 * Bucle principal del programa.
 * Publica los datos de temperatura y velocidad promedio del viento a ThingsBoard
 * a intervalos regulares.
 */
void loop() {
  // Verifica si la conexión WiFi está activa, si no, intenta reconectar
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  // Verifica si la conexión MQTT está activa, si no, intenta reconectar
  if (!mqttClient.connected()) {
    reconnectThingsBoard();
  }

  // Obtener las mediciones de los termopares (temperaturas)
  float* temperatures = ThermocoupleMeasurements();
  sendTemperatureDataToThingsBoard(temperatures);    // Enviar temperaturas a ThingsBoard

  // Obtener la velocidad promedio del viento
  float avgWindSpeed = getAverageWindSpeed();
  sendWindSpeedDataToThingsBoard(avgWindSpeed);      // Enviar velocidad promedio del viento a ThingsBoard

  // Obtener la temperatura del PT1000
  float pt1000Temperature = readPT1000Temperature();
  sendPT1000TemperatureDataToThingsBoard(pt1000Temperature);  // Enviar temperatura radiante a ThingsBoard

  mqttClient.loop();  // Mantiene la conexión MQTT activa
  delay(2000);  // Espera 2 segundos antes de la siguiente medición
}

/**
 * Función para reconectar a la red WiFi.
 * Intenta reconectar si la conexión WiFi se pierde.
 */
void reconnectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);  // Espera y vuelve a intentar
  }
}

/**
 * Función para reconectar a ThingsBoard.
 * Intenta reconectar si la conexión MQTT se pierde.
 */
void reconnectThingsBoard() {
  while (!mqttClient.connected()) {
    if (connectToThingsBoard()) {
      delay(5000);  // Espera 5 segundos antes de intentar nuevamente
    }
  }
}

/**
 * Función para conectarse a ThingsBoard.
 * Conexión usando el token de autenticación definido.
 */
bool connectToThingsBoard() {
  return mqttClient.connect("ArduinoClient", TOKEN, NULL);
}

/**
 * Función para enviar los datos de temperatura a ThingsBoard.
 * Publica los valores de los termopares en los temas MQTT correspondientes.
 *
 * Parámetros:
 * - temperatures: Arreglo con las mediciones de temperatura (TEMP1, TEMP2, TEMP3 y TEMP4).
 */
void sendTemperatureDataToThingsBoard(float* temperatures) {
  for (int i = 0; i < 2; i++) {
    String topic = "v1/devices/me/telemetry";
    String payload = (i == 0) ? "{\"TEMP1\":" + String(temperatures[i]) + "}" : "{\"TEMP2\":" + String(temperatures[i]) + "}" : "{\"TEMP3\":" + String(temperatures[i]) + "}" : "{\"TEMP4\":" + String(temperatures[i]) + "}";
    mqttClient.publish(topic.c_str(), payload.c_str());  // Publica los datos de temperatura
  }
}

/**
 * Función para enviar los datos de velocidad promedio del viento a ThingsBoard.
 * Publica el valor de la velocidad promedio del viento en el tema MQTT correspondiente.
 *
 * Parámetros:
 * - avgWindSpeed: Velocidad promedio del viento (en m/s).
 */
void sendWindSpeedDataToThingsBoard(float avgWindSpeed) {
  String topic = "v1/devices/me/telemetry";
  String payload = "{\"AVG WS\":" + String(avgWindSpeed) + "}";
  mqttClient.publish(topic.c_str(), payload.c_str());  // Publica el dato de velocidad promedio del viento
}

/**
 * Función para enviar los datos de temperatura del PT1000 a ThingsBoard.
 * Publica el valor de la temperatura PT1000 en el tema MQTT correspondiente.
 *
 * Parámetros:
 * - pt1000Temperature: Temperatura radiante (en grados Celsius).
 */
void sendPT1000TemperatureDataToThingsBoard(float pt1000Temperature) {
  String topic = "v1/devices/me/telemetry";
  String payload = "{\"TR\":" + String(pt1000Temperature) + "}";
  mqttClient.publish(topic.c_str(), payload.c_str());  // Publica el dato de temperatura radiante
}
