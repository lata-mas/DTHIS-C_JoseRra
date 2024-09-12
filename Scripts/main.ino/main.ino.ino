#include <WiFiNINA.h>
#include <PubSubClient.h>

// Definiciones de red WiFi y servidor ThingsBoard
#define WIFI_AP "Totalplay-05AF"          // Nombre de la red WiFi
#define WIFI_PASSWORD "05AF13993XNwmHyA"  // Contraseña de la red WiFi

#define TOKEN "1OEilpG3goyYcWLZvuz0"      // Token de acceso para ThingsBoard
#define THINGSBOARD_SERVER "tb.ier.unam.mx" // Dirección del servidor ThingsBoard

#define MQTT_PORT 1883  // Puerto para la comunicación MQTT

// Objetos para la conexión WiFi y MQTT
WiFiClient espClient;  
PubSubClient mqttClient(espClient);  

void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serial a 115200 baudios

  // Conectar a la red WiFi
  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);  // Espera medio segundo entre intentos
    Serial.print(".");  // Imprime un punto mientras intenta conectar
  }
  Serial.println("\nConectado a WiFi");  // Mensaje de confirmación

  // Configurar el cliente MQTT para conectarse al servidor ThingsBoard
  mqttClient.setServer(THINGSBOARD_SERVER, MQTT_PORT);

  // Intentar conectar a ThingsBoard
  if (connectToThingsBoard()) {
    Serial.println("Conectado a ThingsBoard");  // Mensaje de confirmación
  } else {
    Serial.println("Conexión a ThingsBoard fallida");  // Mensaje de error
  }
}

void loop() {
  // Verificar si está conectado al WiFi y reconectar si es necesario
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  // Verificar si está conectado al servidor MQTT y reconectar si es necesario
  if (!mqttClient.connected()) {
    reconnectThingsBoard();
  }

  // Obtener las mediciones de temperatura y enviarlas a ThingsBoard
  float* temperatures = ThermocoupleMeasurements();  // Llamada a la función que obtiene las lecturas de temperatura
  sendTemperatureDataToThingsBoard(temperatures);    // Enviar datos de temperatura a ThingsBoard

  mqttClient.loop();  // Mantener la conexión MQTT activa
  delay(20000);  // Esperar 20 segundos antes de la siguiente iteración
}

// Función para reconectar al WiFi en caso de desconexión
void reconnectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);  // Intentar reconectar a la red WiFi
    delay(500);  // Esperar medio segundo entre intentos
  }
  Serial.println("\nRe-conectado al WiFi");  // Mensaje de confirmación
}

// Función para reconectar al servidor MQTT en caso de desconexión
void reconnectThingsBoard() {
  while (!mqttClient.connected()) {
    if (connectToThingsBoard()) {
      Serial.println("Re-conectado a ThingsBoard");  // Mensaje de confirmación
    } else {
      delay(5000);  // Esperar 5 segundos antes de intentar de nuevo
    }
  }
}

// Función para conectar al servidor MQTT (ThingsBoard)
bool connectToThingsBoard() {
  if (mqttClient.connect("ArduinoClient", TOKEN, NULL)) {
    return true;  // Conexión exitosa
  }
  return false;  // Fallo en la conexión
}

// Función para enviar datos de temperatura a ThingsBoard
void sendTemperatureDataToThingsBoard(float* temperatures) {
  for (int i = 0; i < 2; i++) {
    String topic = "v1/devices/me/telemetry";  // Tema para el envío de datos
    String payload = (i == 0) ? "{\"TEMP1\":" + String(temperatures[i]) + "}" : "{\"TEMP2\":" + String(temperatures[i]) + "}";
    // Publicar el payload en el tema especificado
    mqttClient.publish(topic.c_str(), payload.c_str());
  }
}
