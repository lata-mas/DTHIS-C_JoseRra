def sound_data():
    """
    Función para obtener los datos de sonido desde archivos.

    Retorna:
        dict: Datos de sonido (RMS, dBmax, dBmin).
    """
    archivos = ['/home/hdeza/Sonido/rms.txt', '/home/hdeza/Sonido/dBmax.txt', '/home/hdeza/Sonido/dBmin.txt']
    rms_x = ""
    dBmax_x = ""
    dBmin_x = ""

    for archivo in archivos:
        with open(archivo, 'r', encoding='utf-8') as f:
            if archivo == '/home/hdeza/Sonido/rms.txt':
                rms_x = f.read().strip()
            elif archivo == '/home/hdeza/Sonido/dBmax.txt':
                dBmax_x = f.read().strip()
            elif archivo == '/home/hdeza/Sonido/dBmin.txt':
                dBmin_x = f.read().strip()

    return {'RMS': rms_x, 'dBmax': dBmax_x, 'dBmin': dBmin_x}