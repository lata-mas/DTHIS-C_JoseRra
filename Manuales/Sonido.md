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

![Terminal](Manuales/figs/terminal.png)

En este caso `card 3` es el puerto al que está conectado el micrófono, por lo tanto al ejecutar el comando para la captura de audio, se deberá definir `plughw:3,0`.

### 4. Grabar audio
Para grabar un audio se ejecuta el siguiente comando:
```bash
arecord -D plughw:3,0 -f cd -t wav -d 15 -r 44100 audio.wav
```

---

# Configuración de la cámara en Raspberry Pi 4 y captura de fotos

### 1. Conectar la cámara
- Apaga la Raspberry Pi.
- Conecta la cámara al puerto CSI.
- Asegúrate de que la cinta esté bien conectada, con la parte metálica hacia el conector del puerto.

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
