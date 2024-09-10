import paho.mqtt.client as mqtt
import time
import json
import board
import busio
from publish_thingsboard import thingsboard_data
from scd30 import scd30_measures 

# Obtiene credenciales de ThingsBoard
unique_id, token, thingsboard_host = thingsboard_data()

client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)
client.connect(thingsboard_host, 1883, 60, "")

client.loop_start()

try:
    
    while True:
        # Llama a la función scd30_measures para obtener las lecturas
        sensor_data = scd30_measures()  # Devuelve un diccionario con CO2, T y HR
        
        time.sleep(1)
    
        # Publica todos los datos a ThingsBoard
        client.publish("v1/devices/me/telemetry", json.dumps(sensor_data), 1)
    
        time.sleep(1)
    
        # Imprime los datos para monitoreo local
        print(f"CO2: {sensor_data['CO2']} ppm",
        "Temperatura: {sensor_data['T']}°C",
        "Humedad: {sensor_data['HR']}% \n")
        
        break
    
except KeyboardInterrupt:
    pass

client.loop.stop()
client.disconnect() 