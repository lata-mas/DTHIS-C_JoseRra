# Automatización empleando systemd
Dado que es necesario que los códigos se ejecuten de manera automática al inicializar la Raspberry, se creará un archivo `.service`, una herramienta de automatización. Para ello, desde la terminal, ingrese el siguiente comando:
```bash
sudo nano /etc/systemd/system/archivo.service
```

### 1. SCD30.service
Tras haber accedido al archivo, es necesario modificarlo de la siguiente manera:

```bash
[Unit]
Description=Ejecutar script SCD30 en Raspberry Pi al inicio
After=network.target

[Service]
WorkingDirectory=/home/dthisc/dthis-c/scripts
ExecStart=/home/dthisc/venvs/dthisc/bin/python /home/dthisc/dthis-c/scripts/scd30.py
Environment="PATH=/home/dthisc/venvs/dthisc/bin:/usr/bin"
Restart=always
User=dthisc

[Install]
WantedBy=multi-user.target
```
El archivo se configura para activar el entorno virtual y ejecutar el código en Python cada vez que la `Raspberry` inicialice. Con esto, se debe considerar que el script incluye un método de acceso a `Thingsboard`. La forma de verificar su correcto funcionamiento es confirmar que los datos se envían correctamente a la instancia propia de `Thingsboard`.
