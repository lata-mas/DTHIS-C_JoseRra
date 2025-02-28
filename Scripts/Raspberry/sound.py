import numpy as np

def sound_data():
    """
    Función para obtener los datos de sonido desde archivos y calcular sus valores en dB.

    Retorna:
        dict: Datos de sonido en dB (RMS_dB, dBmax_dB, dBmin_dB).
    """
    archivos = [
        '/home/dthisc/dthis-c/sound/rms.txt',
        '/home/dthisc/dthis-c/sound/dBmax.txt',
        '/home/dthisc/dthis-c/sound/dBmin.txt'
    ]
    
    rms_x = ""
    dBmax_x = ""
    dBmin_x = ""

    for archivo in archivos:
        with open(archivo, 'r', encoding='utf-8') as f:
            if archivo == '/home/dthisc/dthis-c/sound/rms.txt':
                rms_x = round(float(f.read().strip()), 4)
            elif archivo == '/home/dthisc/dthis-c/sound/dBmax.txt':
                dBmax_x = round(float(f.read().strip()), 4)
            elif archivo == '/home/dthisc/dthis-c/sound/dBmin.txt':
                dBmin_x = round(float(f.read().strip()), 4)

    rms_db = round(20 * np.log10(float(rms_x)) + 120, 4)
    dBmax_db = round(20 * np.log10(float(dBmax_x)) + 120, 4)
    dBmin_db = round(20 * np.log10(abs(float(dBmin_x))) + 120, 4)

    return {'RMS': rms_db, 'dBmax': dBmax_db, 'dBmin': dBmin_db}
