#include <WiFiNINA.h>
#include <PubSubClient.h>

#define WIFI_AP "Totalplay-05AF"          
#define WIFI_PASSWORD "05AF13993XNwmHyA"  

#define TOKEN "1OEilpG3goyYcWLZvuz0"      
#define THINGSBOARD_SERVER "tb.ier.unam.mx"

#define MQTT_PORT 1883  

WiFiClient espClient;  
PubSubClient mqttClient(espClient);  

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi");

  mqttClient.setServer(THINGSBOARD_SERVER, MQTT_PORT);

  if (connectToThingsBoard()) {
    Serial.println("Conectado a ThingsBoard");
  } else {
    Serial.println("Conexión a ThingsBoard fallida");
  }
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    reconnectWiFi();
  }

  if (!mqttClient.connected()) {
    reconnectThingsBoard();
  }

  float* temperatures = ThermocoupleMeasurements();  // Llamar a la función desde MAX31856.ino
  sendTemperatureDataToThingsBoard(temperatures);

  mqttClient.loop();
  delay(20000);
}

void reconnectWiFi() {
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);
  }
  Serial.println("\nRe-conectado al WiFi");
}

void reconnectThingsBoard() {
  while (!mqttClient.connected()) {
    if (connectToThingsBoard()) {
      Serial.println("Re-conectado a ThingsBoard");
    } else {
      delay(5000);
    }
  }
}

bool connectToThingsBoard() {
  if (mqttClient.connect("ArduinoClient", TOKEN, NULL)) {
    return true;
  }
  return false;
}

void sendTemperatureDataToThingsBoard(float* temperatures) {
  for (int i = 0; i < 2; i++) {
    String topic = "v1/devices/me/telemetry";
    String payload = (i == 0) ? "{\"TEMP1\":" + String(temperatures[i]) + "}" : "{\"TEMP2\":" + String(temperatures[i]) + "}";
    mqttClient.publish(topic.c_str(), payload.c_str());
  }
}