# Configuración del SCD30 en Raspberry Pi 4

### 1. Habilitar comunicaciones 
Antes de tratar de inicializar cualquier tipo de sensor, se deberán habilitar las siguientes comuncionaciones:
- SPI
- I2C
- Serial Port
- 1-Wire

Para acceder a la configuración, se debe ejecutar el siguiente comando en la terminal:
```bash
sudo raspi-config
```
1. Dentro del menú, es necesario dirigirse al apartado `Interface Options`.
2. Seleccionar uno por uno: SPI, I2C, Serial Port, 1-Wire.
3. Al finalizar se reiniciaría la Raspberry.

### 2. Crear un ambiente virtual
Dentro de la terminal, se creará un directorio que albergue los ambientes virtuales, así mismo dentro de dicho folder, se creará el ambiente ejecutando las siguientes líneas:
```bash
mkdir venvs
cd venvs
python -m venv dthis-c
```

Tras haberse creado, debe activarse con el siguiente comando:
```bash
source venvs/dthis-c/bin/activate
```

### 3. Instalar librerías 
Las librerías necesarías para ejecutar los scripts de cada sensor que compone al `DTHIS-C` pueden obtenerse al instalar [requirements.txt](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/requirements.txt) dentro del entorno virtual.

1. Activa el entorno virtual:
```bash
source venvs/dthis-c/bin/activate
```
2. Instala las dependencias desde el archivo `requirements.txt`:
```bash
python -m pip install -r requirements.txt
```

### 4. Grabar audio
Para grabar un audio se ejecuta el siguiente comando:
```bash
arecord -D plughw:3,0 -f cd -t wav -d 15 -r 44100 audio.wav
```

---

# Creación de un programa para la obtención de datos de los audios

### 1. Crear scripts acorde a las funciones 
- [grabar.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/grabar.sh): Graba 15 segundos de audio en calidad CD. 
- [dBmax.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/dBmax.sh): Extrae la amplitud máxima del archivo de audio.
- [dBmin.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/dBmin.sh): Extrae la amplitud mínima del archivo de audio.
- [rms.sh](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/Sonido/rms.sh): Extrae la amplitud RMS, una medida de la potencia promedio del audio.

### 2. Crear un ejecutable para correr todos los scripts
Para evitar que la Raspberry Pi falle por sobrecarga de procesos, se creará un archivo ejecutable `.e` que ejecutará los scripts secuencialmente, asegurando que no haya conflictos entre las instrucciones. Es fundamental especificar la ruta completa del directorio y activar el entorno virtual antes de ejecutar el script que envía la información a ThingsBoard. 

El archivo se crea de la siguiente manera:
```bash
vim executable.e
```

Y su contenido debe ser el siguiente:
```bash
/home/hdeza/Sonido/grabar.sh
/home/hdeza/Sonido/dBmax.sh
/home/hdeza/Sonido/dBmin.sh
/home/hdeza/Sonido/rms.sh
/home/hdeza/venvs/dthis-c/bin/python3 /home/hdeza/dthis/scripts/sound.py
```
