#include <WiFiNINA.h>
#include <PubSubClient.h>

// Definiciones para la red WiFi y ThingsBoard
#define WIFI_AP "IER"          
#define WIFI_PASSWORD "acadier2014" 
#define TOKEN "bXQq1eepFYJV3nldvLTV"
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
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);  // Conectar a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);  // Espera hasta conectarse
  }
  
  mqttClient.setServer(THINGSBOARD_SERVER, MQTT_PORT);
  connectToThingsBoard();  // Conectar a ThingsBoard
}

/**
 * Ciclo principal del programa.
 * Mantiene las conexiones y realiza las tareas periódicas.
 */
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();  // Reconecta WiFi si es necesario
  }
  
  if (!mqttClient.connected()) {
    reconnectThingsBoard();  // Reconecta MQTT si es necesario
  }

  // Obtener las mediciones de los termopares (temperaturas)
  float* temperatures = ThermocoupleTemp();
  sendTC(temperatures);    // Enviar temperaturas a ThingsBoard

  // Obtener la temperatura del TPF1
  float radiant = TPF1Temp();
  sendRT(radiant);  // Enviar temperatura radiante a ThingsBoard

  // Obtener la velocidad promedio del viento
  float* windspeed = WindSensor();
  sendWS(windspeed);      // Enviar velocidad del viento a ThingsBoard

  mqttClient.loop();
  delay(2000);  // Espera 2 segundos antes de la siguiente iteración
}

/**
 * Conecta a la red WiFi.
 */
void connectWiFi() {
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);  // Espera hasta conectarse
  }
}

/**
 * Reconecta a la red WiFi si es necesario.
 */
void reconnectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);
  }
}

/**
 * Reconecta a ThingsBoard si es necesario.
 */
void reconnectThingsBoard() {
  while (!mqttClient.connected()) {
    connectToThingsBoard();
    delay(5000);  // Espera antes de reintentar
  }
}

/**
 * Conecta a ThingsBoard usando el token de autenticación.
 */
bool connectToThingsBoard() {
  return mqttClient.connect("ArduinoClient", TOKEN, NULL);
}

/**
 * Envía los datos de temperatura.
 */
void sendTC(float* temperatures) {
  String topic = "v1/devices/me/telemetry";
  String payload = "{\"T1\":" + String(temperatures[0]) + 
                   ", \"T2\":" + String(temperatures[1]) + 
                   ", \"T3\":" + String(temperatures[2]) + 
                   ", \"T4\":" + String(temperatures[3]) + "}";
  mqttClient.publish(topic.c_str(), payload.c_str());
}

/**
 * Envía los datos de temperatura radiante.
 */
void sendRT(float radiant) {
  String topic = "v1/devices/me/telemetry";
  String payload = "{\"TR\":" + String(radiant) + "}";
  mqttClient.publish(topic.c_str(), payload.c_str());  
}

/**
 * Envía los datos de velocidad del viento.
 */
void sendWS(float* windspeed) {
  String topic = "v1/devices/me/telemetry";
  String payload = "{\"WS\":" + String(windspeed[0]) + 
                   ", \"TEMP\":" + String(windspeed[1]) + "}";
  mqttClient.publish(topic.c_str(), payload.c_str());
}
