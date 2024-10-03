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

### 4. Instalar libcamera
```bash
sudo apt install libcamera-apps
```

### 5. Tomar una foto
```bash
libcamera-still -o imagen.jpg
```

---

# Instalación de Radiance 

### 1. Instala las dependencias necesarias:
```bash
sudo apt install csh make gcc g++ libx11-dev tcl tk
```

### 2. Descarga Radiance y el soporte adicional:
```bash
wget https://www.radiance-online.org/software/snapshots/radiance-HEAD.tgz
wget https://www.radiance-online.org/download-install/radiance-source-code/latest-release/rad5R4supp.tar.gz
```

### 3. Descarga `config.guess` y `config.sub`:
```bash
wget -O config.guess 'http://git.savannah.gnu.org/gitweb/?p=config.git;a=blob_plain;f=config.guess;hb=HEAD'
wget -O config.sub 'http://git.savannah.gnu.org/gitweb/?p=config.git;a=blob_plain;f=config.sub;hb=HEAD'
```

### 4. Descomprime los archivos descargados:
```bash
tar -xvzf radiance-HEAD.tgz
tar -xvzf rad5R4supp.tar.gz
```

### 5. Copia `config.sub` y `config.guess` al directorio `px/tiff/`:
```bash
cp config.sub ray/src/px/tiff/
cp config.guess ray/src/px/tiff/
```

### 6. Entra en el directorio `ray/` y compila la librería:
```bash
cd ray/
sudo ./makeall library
```

### 7. Agrega la siguiente línea al archivo `.profile` para configurar el `RAYPATH`:
```bash
/usr/local/lib/ray
```

### 8. Compila todo el proyecto:
```bash
sudo ./makeall install
```

---

# Creación de un script de shell con vim

### 1. Abre `vim` y crea un nuevo archivo de script:
```bash
vim script.sh
```

### 2. Entra en el **modo de inserción** presionando la tecla `i`.

### 3. Escribe el contenido del script:
```bash
#!/bin/bash
echo "Hola, este es mi primer script!"
```

### 4. Una vez que hayas terminado de escribir el script, presiona `Esc` para salir del **modo de inserción**.

### 5. Guarda el archivo y sal de `vim` escribiendo `:wq` y presionando `Enter`. Esto significa:
- `w` para guardar el archivo.
- `q` para salir de `vim`.

### 6. Haz el script ejecutable con el siguiente comando:
```bash
chmod +x script.sh
```

### 7. Ejecuta el script:
```bash
./script.sh
```
