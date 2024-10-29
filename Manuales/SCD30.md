# Configuración del SCD30 en Raspberry Pi 4

### 1. Ensamblar el circuito
Para la conexión del sensor SCD30, se requiere una Raspberry Pi 4 Model B y los cables de conexión (jumpers) incluidos con el sensor, que permiten la conexión directa al microcontrolador. Las conexiones deben realizarse de acuerdo con el siguiente diagrama:
![SCD30](figs/scd30.png)

### 2. Crear script de Python
El script [scd30.py](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/scd30.py) inicializa el sensor `SCD30` y obtiene lecturas de la `concentración de CO2`, `temperatura` y `humedad relativa` para devolverlos como una tupla (CO2, T, HR) al final. 

### 3. Habilitar crontab
Ya que nos interesa que este codigo se ejecute automaticamente cada cierto tiempo usaremos una herramienta para automatizarlo, desde la terminal teclea lo sig:
```
crontab -e
```bash
Cambiara de interfaz y nos dirigimos hasta la parte final y ponemos lo siguiente:
```bash
*/2 * * * * /bin/bash -c 'source /home/pi/SCD30/bin/activate && /home/pi/SCD30/bin/python3 /home/pi/DTHIS_jorge/t_hr_co2.py' >> /home/pi/DTHIS_jorge/t_hr_co2.log 2>&1
```
Lo que le decimos al crontab es que active el ambiente virtual y luego ejecute el codigo en python y mandar los errores a un archivo dado.

Y listo, hay que tomar en cuenta que en el codigo muetra una manera de acceso al Thingsboard cada quien personaliza esa parte, y la manera de comprobar que funciona es que tus datos son enviados correctamente a tu propio Thingsboard.
