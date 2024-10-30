# Automatización empleando crontab
Dado que es necesario que los códigos se ejecuten de manera automática al inicializar la Raspberry, se empleará `crontab`, una herramienta de automatización. Para ello, desde la terminal, ingrese el siguiente comando:
```bash
crontab -e
```

### 1. SCD30
Tras haber accedido al archivo del crontab, es necesario modificarlo con la siguiente línea:

```bash
*/5 * * * * /bin/bash -c "source /home/dthisc/venvs/dthisc/bin/activate && /home/dthisc/venvs/dthisc/bin/python3 /home/dthisc/dthis-c/scripts/scd30.py" >> /home/dthisc/dthis-c/scripts/scd30.py.log 2>&1
```
El comando en el crontab se configura para activar el entorno virtual y ejecutar el código en Python. Con esto, se debe considerar que el script incluye un método de acceso a `Thingsboard`. La forma de verificar su correcto funcionamiento es confirmar que los datos se envían correctamente a la instancia propia de `Thingsboard`.
