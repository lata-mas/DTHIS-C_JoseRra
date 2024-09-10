import time
import board
import busio
from scd30_i2c import SCD30

def scd30_measurements():
    """
    Función para obtener las lecturas de CO2, Temperatura y Humedad Relativa del sensor SCD30.

    Retorna:
        tuple: (CO2, T, HR) donde
            CO2: concentración de CO2 en ppm
            T: temperatura en grados Celsius
            HR: humedad relativa en porcentaje
    """
    # Inicializa el sensor SCD30
    scd30 = SCD30()
    # Espera para asegurarse de que el sensor esté listo
    time.sleep(2)  
    
    # Verifica si los datos están listos para ser leídos
    if scd30.get_data_ready():
        # Lee las mediciones del sensor
        CO2, T, HR = scd30.read_measurement()
        return CO2, T, HR