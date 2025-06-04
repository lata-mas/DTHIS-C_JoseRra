import time
import json
import paho.mqtt.client as mqtt
from scd30_i2c import SCD30
from thingsboard_credentials import thingsboard_data


# Configuración de ThingsBoard / MQTT
unique_id, token, thingsboard_host = thingsboard_data()

client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)
client.connect(thingsboard_host, 1883, 60, '')
client.loop_start()

# Diccionario de telemetría
sensor_data = {'CO2': 0, 'T': 0, 'HR': 0}

try:
    # Inicializar el sensor
    scd30 = SCD30()
    # Pausa inicial para que el sensor arranque
    time.sleep(2)

    while True:
        # Verificar si hay datos listos
        if scd30.get_data_ready():
            CO2, T, HR = scd30.read_measurement()
            # Redondear a 2 decimales
            CO2 = round(CO2, 2)
            T   = round(T, 2)
            HR  = round(HR, 2)

            # Actualizar y publicar
            sensor_data['CO2'] = CO2
            sensor_data['T']   = T
            sensor_data['HR']  = HR

            payload = json.dumps(sensor_data)
            client.publish('v1/devices/me/telemetry', payload, qos=1)

        # Esperar intervalo
        time.sleep(10)
        
except KeyboardInterrupt:
    pass

client.loop_stop()
client.disconnect()
