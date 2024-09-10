import paho.mqtt.client as mqtt
import json
import time
import math

def thingsboard_data():
    """
    Proporciona los datos de identificación y autenticación necesarios para conectarse
    a la plataforma de IoT ThingsBoard.

    Retorna:
        unique_id (str): Identificador único del dispositivo en ThingsBoard.
        token (str): Token de autenticación que permite una conexión segura al servidor MQTT de ThingsBoard.
        thingsboard_host (str): Dirección del servidor de ThingsBoard.

    Estos valores son esenciales para autenticar y conectar el dispositivo a la plataforma
    utilizando el protocolo MQTT.
    """
    # Identificador único del dispositivo en ThingsBoard
    unique_id = '7b239940-6f1d-11ef-b3cc-4fb2ff6d45a9'

    # Token de autenticación para acceder a la plataforma ThingsBoard
    token = '1OEilpG3goyYcWLZvuz0'

    # Dirección del servidor ThingsBoard
    thingsboard_host = 'tb.ier.unam.mx'

    return unique_id, token, thingsboard_host