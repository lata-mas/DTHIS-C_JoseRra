def sound_data():
    """
    Función para obtener los datos de sonido desde archivos y redondearlos a dos decimales.

    Retorna:
        dict: Datos de sonido (RMS, dBmax, dBmin) redondeados.
    """
    archivos = ['/home/hdeza/Sonido/rms.txt', '/home/hdeza/Sonido/dBmax.txt', '/home/hdeza/Sonido/dBmin.txt']
    rms_x = ""
    dBmax_x = ""
    dBmin_x = ""

    for archivo in archivos:
        with open(archivo, 'r', encoding='utf-8') as f:
            if archivo == '/home/hdeza/Sonido/rms.txt':
                rms_x = round(float(f.read().strip()), 4)
            elif archivo == '/home/hdeza/Sonido/dBmax.txt':
                dBmax_x = round(float(f.read().strip()), 4)
            elif archivo == '/home/hdeza/Sonido/dBmin.txt':
                dBmin_x = round(float(f.read().strip()), 4)

    return {'RMS': rms_x, 'dBmax': dBmax_x, 'dBmin': dBmin_x}
