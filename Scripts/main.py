import paho.mqtt.client as mqtt
import time
import json
from publish_thingsboard import thingsboard_data
from scd30 import scd30_measurements

# Obtiene los datos de conexión para ThingsBoard
unique_id, token, thingsboard_host = thingsboard_data()

# Diccionario para almacenar las lecturas del sensor
sensor_data = {'CO2': 0, 'T': 0, 'HR': 0}

# Configura el cliente MQTT
client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)
client.connect(thingsboard_host, 1883, 60, '')
client.loop_start()

try:
    while True:
        # Obtiene las mediciones del sensor SCD30
        CO2, T, HR = scd30_measurements()

        # Actualiza el diccionario con las lecturas actuales
        sensor_data['CO2'] = CO2
        sensor_data['T'] = T
        sensor_data['HR'] = HR

        # Publica los datos en ThingsBoard
        client.publish('v1/devices/me/telemetry', json.dumps(sensor_data), 1)

        # Imprime los datos para monitoreo local
        print(f'CO2: {round(CO2, 2)} ppm')
        print(f'Temperatura: {round(T, 2)}°C')
        print(f'Humedad: {round(HR, 2)}% \n')

        time.sleep(1)  # Ajusta el intervalo de tiempo entre lecturas

except KeyboardInterrupt:
    pass

# Detiene el loop del cliente MQTT y desconecta del servidor
client.loop_stop()
client.disconnect()