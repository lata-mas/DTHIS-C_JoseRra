# Configuración de crontab en Raspberry Pi

Para automatizar la ejecución periódica de los scripts del DTHIS-C, se utiliza `cron` y el archivo `crontab`. A continuación se describe el proceso de configuración paso a paso.

---

### 1. Hacer los scripts ejecutables

Antes de agendar cualquier tarea en `crontab`, asegúrate de que todos los archivos que deben ejecutarse directamente tengan permisos de ejecución. Por ejemplo, desde la terminal de tu Raspberry Pi:

```bash
chmod +x /home/dthisc/dthis-c/scd30.py
chmod +x /home/dthisc/dthis-c/sound/executable.e
chmod +x /home/dthisc/dthis-c/sonido.py
chmod +x /home/dthisc/dthis-c/illuminance/createHDR.sh
chmod +x /home/dthisc/dthis-c/iluminancia.py
```

### 2. Verificar el contenido actual de crontab

Para revisar las entradas existentes en el crontab del usuario, ejecuta:

```bash
crontab -l
```

### 3. Editar el crontab
Para agregar o modificar las tareas programadas, abre el editor de crontab:

```bash
crontab -e
```

En el editor que se abra (normalmente nano o vim), pega las siguientes líneas al final del archivo:

```bash
# Ejecutar scd30.py cada minuto
* * * * * /bin/bash -c 'source /home/dthisc/venvs/dthisc/bin/activate && /home/dthisc/venvs/dthisc/bin/python3 /home/dthisc/dthis-c/scd30.py' >> /home/dthisc/dthis-c/scd30.log 2>&1

# Ejecutar sonido (ejecutable) cada 2 minutos
*/2 * * * * /home/dthisc/dthis-c/sound/executable.e >> /home/dthisc/dthis-c/sound/errores_e.log 2>&1

# Ejecutar sonido.py cada 2 minutos
*/2 * * * * /bin/bash -c 'source /home/dthisc/venvs/dthisc/bin/activate && /home/dthisc/venvs/dthisc/bin/python3 /home/dthisc/dthis-c/sonido.py' >> /home/dthisc/dthis-c/sonido.log 2>&1

# Ejecutar createHDR.sh cada 30 minutos
*/30 * * * * /home/dthisc/dthis-c/illuminance/createHDR.sh >> /home/dthisc/dthis-c/illuminance/createHDR.log 2>&1

# Ejecutar iluminancia.py cada 30 minutos
*/30 * * * * /bin/bash -c 'source /home/dthisc/venvs/dthisc/bin/activate && /home/dthisc/venvs/dthisc/bin/python3 /home/dthisc/dthis-c/iluminancia.py' >> /home/dthisc/dthis-c/iluminancia.log 2>&1
```

Se usa >> `archivo.log 2>&1` para redirigir tanto la salida estándar como los errores a un archivo de log.

En los comandos Python, se activa primero el entorno virtual (`venvs/dthisc`) para asegurar que se usen las dependencias correctas.

Guarda el archivo y cierra el editor (en `nano`: `Ctrl+O`, `Enter`, `Ctrl+X`; en `vim`: `:wq`).
