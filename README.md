# DTHIS-C

El **DTHIS-C** (Dispositivo de Temperatura, Humedad, Iluminación y Sonido de Campaña) está diseñado para medir y evaluar condiciones ambientales tanto en interiores como en exteriores. Su principal ventaja es su portabilidad y su capacidad para adquirir datos sin necesidad de una red WiFi, haciéndolo ideal para campañas en sitios remotos o situaciones que requieren movilidad.

## Variables que mide el DTHIS-C

El dispositivo está equipado para medir una amplia gama de variables, tales como:

- **Temperatura del aire** a diferentes alturas:
  1. 0.1 m
  2. 0.6 m
  3. 1.1 m
  4. 1.7 m
- **Temperatura radiante**
- **Humedad relativa**
- **Velocidad y dirección del viento**
- **Concentración de CO₂**
- **Mapas de luminancia** para evaluar la iluminación
- **Deslumbramiento**
- **Niveles de sonido**

---

## Composición del DTHIS-C

El dispositivo se compone de los siguientes sensores y componentes electrónicos:

| **Sensor**                                    | **Variable**     | **Cantidad** | **Comunicación** | **Microcontrolador**    |
|-----------------------------------------------|------------------|--------------|------------------|-------------------------|
| Termopar tipo T                               | To               | 4            | ICSP             | Arduino UNO R4 WiFi      |
| TPF1/E-PT1000                                 | Tr               | 1            | ICSP             | Arduino UNO R4 WiFi      |
| Wind Sensor Rev P                             | WS y Dirección   | 1            | ADC              | Arduino UNO R4 WiFi      |
| SCD30 Sensirion                               | CO₂ y HR         | 1            | I2C              | Raspberry Pi 4           |
| 5MP OV5647 Wide Angle Fisheye Camera          | Luminancia       | 1            | SCI              | Raspberry Pi 4           |
| Micrófono ambiental USB                       | Sonido           | 1            | USB              | Raspberry Pi 4           |

---

## Participantes del proyecto

El equipo responsable del desarrollo y construcción del DTHIS-C está conformado por los siguientes integrantes:

| **Nombre**                  | **Instituto/Organización** | **Email**             |
|-----------------------------|----------------------------|-----------------------|
| Guillermo Barrios del Valle  | IER-UNAM                   | gbv@ier.unam.mx       |
| Guillermo Ramírez Zúñiga     | IER-UNAM                   | guraz@ier.unam.mx     |
| Jorge Luis Méndez Reyna      | IER-UNAM                   | merejo@ier.unam.mx    |
| Julio César Landa López      | IER-UNAM                   | jclalo@ier.unam.mx    |
| José Ramón Hernández Aguilar | IER-UNAM                   | jrha@ier.unam.mx      |
| Debra Paola López Domínguez  |                            | dpld@ier.unam.mx      |
| Edgar Gallardo Pérez         |                            |                       |

---

> [!Tip]
> Este repositorio está diseñado para simplificar el desarrollo y uso del dispositivo **DTHIS-C**. Con su uso, podrás acceder a múltiples recursos clave para su implementación y operación eficiente:
> 
> ### 1. Uso de sensores
> Cada sensor integrado en el DTHIS-C tiene su propio directorio en el repositorio, dentro de los cuales encontrarás:
> - **Consejos prácticos** para una correcta implementación.
> - **Esquemas de conexión** detallados que facilitan el montaje.
> - **Código funcional** específico para cada sensor.
>
> ### 2. Integración con ThingsBoard
> El repositorio incluye un **script central** que recopila las mediciones de todos los sensores y las envía a la plataforma **ThingsBoard** mediante el protocolo **MQTT**. Esto permite la monitorización en tiempo real de las variables, accesible desde cualquier lugar con conexión a la plataforma.
>
> ### 3. Manual de uso y ensamblaje
> Además, el repositorio ofrece un manual detallado que cubre:
> - **Esquemas de conexión** y **diagramas eléctricos**.
> - **Instrucciones paso a paso** para el ensamblaje del DTHIS-C, lo que facilita su construcción desde cero.
>
> ---
> Este repositorio es útil tanto para trabajar con sensores de forma individual como para la construcción completa del dispositivo DTHIS-C.
