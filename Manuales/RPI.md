# Configuración general de la Raspberry Pi 4

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
3. Al finalizar se reiniciará la Raspberry.

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

### 3. Instalar bibliotecas 
Las bibliotecas necesarias para ejecutar los scripts de Python de cada sensor que forma parte del DTHIS-C se pueden obtener instalando el archivo [requirements.txt](https://github.com/lata-mas/DTHIS-C_JoseRra/blob/main/Scripts/Raspberry/requirements.txt) dentro del entorno virtual.

1. Activa el entorno virtual:
```bash
source venvs/dthis-c/bin/activate
```
2. Instala las dependencias desde el archivo `requirements.txt`:
```bash
python -m pip install -r requirements.txt
```
