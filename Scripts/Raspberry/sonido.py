import numpy as np
import time
import paho.mqtt.client as mqtt
import json
from thingsboard_credentials import thingsboard_data

unique_id, token, thingsboard_host = thingsboard_data()

archivos = [
        '/home/dthisc/dthis-c/sound/rms.txt',
        '/home/dthisc/dthis-c/sound/dBmax.txt',
        '/home/dthisc/dthis-c/sound/dBmin.txt'
        ]

rms_x  = ""
dBmax_x = ""
dBmin_x = ""
            
for archivo in archivos:
    with open(archivo, 'r', encoding='utf-8') as f:
        if archivo == '/home/dthisc/dthis-c/sound/rms.txt':
            rms_x = round(float(f.read().strip()), 4)
        elif archivo == '/home/dthisc/dthis-c/sound/dBmax.txt':
            dBmax_x = round(float(f.read().strip()), 4)
        elif archivo == '/home/dthisc/dthis-c/sound/dBmin.txt':
            dBmin_x = round(float(f.read().strip()), 4)

rms_db = round(20 * np.log10(rms_x) + 120, 2)
dBmax_db = round(20 * np.log10(dBmax_x) + 120, 2)
dBmin_db = round(20 * np.log10(abs(dBmin_x)) + 120, 2)

micro_data = {'RMS': rms_db,'dBmax': dBmax_db,'dBmin': dBmin_db}

client = mqtt.Client(unique_id, False)
client.username_pw_set(token, password=None)

client.connect(thingsboard_host, 1883, 60, "")
client.loop_start()
time.sleep(2)

try:
    client.publish('v1/devices/me/telemetry', json.dumps(micro_data))
except KeyboardInterrupt:
    pass

client.loop_stop()
client.disconnect()
