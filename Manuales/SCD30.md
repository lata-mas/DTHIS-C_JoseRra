# Configuración del SCD30 en Raspberry Pi 4

### 1. Ensamblar circuito
Para conectar el sensor solo necesitaremos de una Raspi 4 Model B, la mayoria de sensores SCD30 ya vienen con jumpers para conectar direvcto, en caso contrario solamente usar cables jumpers hembra-hembra y conectarlo como el siguiente diagrama:
![SCD30](figs/scd3.png)

### 2. Crear script de Python
Ahora vamos a crear un script con el código poniendo el siguiente comando en la terminal:
```
nano
```
Utiliza el codigo anexado a este repositorio, despues _ctrl + O_ para guardar, te dice que asignes un nombre, recuerda que termina con .py y por ultimo _ctrl + X_ para salir.
