import paho.mqtt.client as mqtt
import json
import time
from thingsboard_credentials import thingsboard_data
from scd30 import scd30_measurements
from sound import sound_data

# Obtiene los datos de conexión para ThingsBoard
unique_id, token, thingsboard_host = thingsboard_data()

# Configura el cliente MQTT
client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)
client.connect(thingsboard_host, 1883, 60, '')
client.loop_start()

try:
    while True:
        # Obtiene las mediciones del sensor SCD30
        sensor_data = scd30_measurements()
        # Publica los datos del SCD30 en ThingsBoard
        client.publish('v1/devices/me/telemetry', json.dumps(sensor_data), 1)

        # Obtiene los datos de sonido
        micro_data = sound_data()
        # Publica los datos de sonido en ThingsBoard
        client.publish('v1/devices/me/telemetry', json.dumps(micro_data), 1)

        time.sleep(2)  # Intervalo de tiempo entre lecturas

except KeyboardInterrupt:
    pass

# Detiene el loop del cliente MQTT y desconecta del servidor
client.loop_stop()
client.disconnect()
