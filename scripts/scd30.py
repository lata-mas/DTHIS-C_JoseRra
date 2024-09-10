import time
import board
import busio
from scd30_i2c import SCD30

def scd30_measures():
    """
    Lee los datos del sensor SCD30 de forma continua y los imprime por consola.

    """
    scd30 = SCD30()
    sensor_data = {'T': 0,'HR': 0, 'CO2': 0} 

    while True:
        if scd30.get_data_ready():
            CO2, T, HR = scd30.read_measurement()
        
        sensor_data['CO2'] = CO2
        sensor_data['T'] = T
        sensor_data['HR'] = HR
        time.sleep(1) # Ajusta el tiempo de espera
            
        print(f"CO2: {round(CO2, 2)} ppm")
        print(f"Temperatura: {round(T, 2)}°C")
        print(f"Humedad: {round(HR, 2)}% \n")