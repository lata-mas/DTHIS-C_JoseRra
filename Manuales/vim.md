# Creación de un script de shell con vim

### 1. Crear archivo de script
```bash
vim script.sh
```

### 2. Escribir contenido del script
Entra en el **modo de inserción** presionando la tecla `i`.
```bash
#!/bin/bash
echo "Hola, este es mi primer script!"
```

### 3. Guardar y salir de vim
Presiona `Esc`, escribe `:wq` o `x`, y presiona `Enter`.

### 4. Hacer ejecutable el script
```bash
chmod +x script.sh
```

### 5. Ejecutar el script
```bash
./script.sh
```
