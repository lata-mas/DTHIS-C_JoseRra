# Configuración del micrófono en Raspberry Pi 4

### 1. Conectar el micrófono
- Apaga la Raspberry Pi.
- Conecta el micrófono a un puerto USB.

### 2. Instalar paqueterías
```bash
sudo apt update
sudo apt install alsa-utils
sudo apt install sox libsox-fmt-all
```

### 3. Comprobar micrófono
Para identificar a que puerto está conectado el micrófono, ejecuta el siguiente comando:
```bash
arecord -l
```
Se desplegará lo siguiente:

![Terminal](figs/terminal.png)

En este caso `card 3` es el puerto al que está conectado el micrófono, por lo tanto al ejecutar el comando para la captura de audio, se deberá definir `plughw:3,0`.

### 4. Grabar audio
Para grabar un audio se ejecuta el siguiente comando:
```bash
arecord -D plughw:3,0 -f cd -t wav -d 15 -r 44100 audio.wav
```

---

# Creación de un programa para la obtención de datos de los audios

### 1. Crear scripts acorde a las funciones 
- [grabar.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/grabar.sh): 
- [dBmax.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/dBmax.sh)):
- [dBmin.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/dBmin.sh)):
- [rms.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/rms.sh):

### 2. Actualizar el sistema
```bash
sudo apt update && sudo apt upgrade
```

### 3. Reiniciar Raspberry Pi
```bash
sudo reboot
```

### 4. Tomar una foto
```bash
rpicam-still -o imagen.jpg
```
