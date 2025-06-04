import time
import json
import paho.mqtt.client as mqtt
from thingsboard_credentials import thingsboard_data


unique_id, token, thingsboard_host = thingsboard_data()

archivo = '/home/dthisc/dthis-c/illuminance/illuminance.txt'

ilum = ""
with open(archivo, 'r', encoding='utf-8') as f:
    ilum = round(float(f.read().strip()), 2)

camera_data = {'Iluminancia': ilum}

# Configurar MQTT
client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)

client.connect(thingsboard_host, 1883, 60, "")
client.loop_start()
time.sleep(2)

# Publicar telemetría
try:
    client.publish('v1/devices/me/telemetry', json.dumps(camera_data))
except KeyboardInterrupt:
    pass

client.loop_stop()
client.disconnect()
