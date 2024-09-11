# DTHIS-C

El dispositivo **DTHIS-C** (Dispositivo de Temperatura, Humedad, Iluminación y Sonido de Campaña) está diseñado para evaluar las condiciones ambientales en interiores y exteriores, permitiendo la medición precisa de una amplia gama de variables. Este equipo portátil no requiere conexión a una red WiFi para la adquisición de datos, lo que lo hace ideal para campañas en sitios remotos o situaciones donde la movilidad es fundamental.

El DTHIS-C mide las siguientes variables:

- **Temperatura del aire** a distintas alturas:
  1. 0.1 m
  2. 0.6 m
  3. 1.1 m
  4. 1.7 m
- **Temperatura radiante**
- **Humedad relativa**
- **Velocidad y dirección del viento**
- **Niveles de CO2**
- **Mapas de luminancia** para evaluar la iluminación
- **Deslumbramiento**
- **Sonido**


### Composición del DTHIS-C

| **Sensor**                                    | **Variable**     | **Cantidad** | **Comunicación** | **Microcontrolador**    |
|-----------------------------------------------|------------------|--------------|------------------|-------------------------|
| Termopar tipo T                               | To               | 4            | ICSP             | Arduino UNO R4 WiFi      |
| TPF1/E-PT1000                                 | Tr               | 1            | ICSP             | Arduino UNO R4 WiFi      |
| Wind Sensor Rev P                             | WS y Dirección   | 1            | ADC              | Arduino UNO R4 WiFi      |
| SCD30 Sensirion                               | CO₂ y HR         | 1            | I2C              | Raspberry Pi 4           |
| 5MP OV5647 Wide Angle Fisheye Camera          | Luminancia       | 1            | SCI              | Raspberry Pi 4           |
| Micrófono ambiental USB                       | Sonido           | 1            | USB              | Raspberry Pi 4           |


> [!Tip]
> Este repositorio está diseñado para simplificar el desarrollo y uso del dispositivo **DTHIS-C**. Dentro de este repositorio usted podrá encontrar:
>
> - **Uso de sensores**: Cada sensor del DTHIS-C tiene su propio directorio, que incluye:
>   - Recomendaciones para la correcta implementación.
>   - Esquemas de conexión detallados.
>   - Código funcional específico para cada sensor.
>
> - **ThingsBoard**: Un script central integra las mediciones de todos los sensores y las envía a **ThingsBoard** vía **MQTT**, permitiendo la monitorización en tiempo real desde cualquier ubicación con acceso a la plataforma.
>
> - **Manual de uso y ensamblaje**: Una guía completa que cubre:
>   - Esquemas de conexión y diagramas eléctricos.
>   - Instrucciones paso a paso para ensamblar el DTHIS-C.
>   >
> Este repositorio es útil tanto para trabajar con sensores individuales como para la construcción integral del dispositivo.


------------


### 1.2 Participantes del proyecto

|Nombre|Instituto/Organización|Email|
| ------------ | ------------ | ------------ |
|Autor 1| | |
|Autor 2| | |
|Autor 3| | |
|Guillermo Barrios del Valle|IER-UNAM|gbv@ier.unam.mx|
|Guillermo Ramírez Zúñiga|IER-UNAM|guraz@ier.unam.mx|
