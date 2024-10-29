# Configuración del SCD30 en Raspberry Pi 4

### 1. Ensamblar el circuito
Para la conexión del sensor SCD30, se requiere una Raspberry Pi 4 Model B y los cables de conexión (jumpers) incluidos con el sensor, que permiten la conexión directa al microcontrolador. Las conexiones deben realizarse de acuerdo con el siguiente diagrama:
![SCD30](figs/scd30.png)

### 2. Crear script de Python
El script [scd30.py](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/scd30.py)inicializa el sensor `SCD30` y obtiene lecturas de la `concentración de CO2`, `temperatura` y `humedad relativa` para devolverlos como una tupla (CO2, T, HR) al final. 
