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

| **Sensor**                                    | **Variable**                       | **Cantidad** | **Comunicación** | **Microcontrolador**     |
|-----------------------------------------------|------------------------------------|--------------|------------------|--------------------------|
| Termopar tipo T                               | Temperatura Ambiente               | 4            | ICSP             | Arduino UNO R4 WiFi      |
| TPF1/E-PT1000                                 | Temperatura Radiante               | 1            | ICSP             | Arduino UNO R4 WiFi      |
| Wind Sensor Rev P                             | Velocidad y Dirección del viento   | 1            | ADC              | Arduino UNO R4 WiFi      |
| SCD30 Sensirion                               | CO₂ y HR                           | 1            | I2C              | Raspberry Pi 4           |
| 5MP OV5647 Wide Angle Fisheye Camera          | Luminancia                         | 1            | SCI              | Raspberry Pi 4           |
| Micrófono ambiental USB                       | Sonido                             | 1            | USB              | Raspberry Pi 4           |


---


## Elementos del repositorio
-  #### En [**docs**](https://github.com/Dispositivos-Edificio-Bioclimatico/DTHIS/tree/master/docs) encontramos
	-  Lista de materiales y costos
	-  Manual de operación
	-  Fichas técnicas o datasheet de los módulos, sensores y componentes usados
	- Documento de errores, soluciones y recomendaciones

-  #### En [**diagramas**](https://github.com/Dispositivos-Edificio-Bioclimatico/DTHIS/tree/master/diagrama) encontramos
	- Pictograma de conexión
	- Esquemático de conexión
	
-  #### En [**codigo**](https://github.com/Dispositivos-Edificio-Bioclimatico/DTHIS/tree/master/codigo) encontramos
	- Códigos completos
	- Librerías a usar.
	- Explicación.
-  #### En [**carcasa**](https://github.com/Dispositivos-Edificio-Bioclimatico/DTHIS/tree/master/cad) encontramos
	-  Planos CAD
	-  Archivos de diseño CAD
	-  Archivos STL para impresión 3D


---


## Participantes del proyecto

El equipo responsable del desarrollo y construcción del DTHIS-C está conformado por los siguientes integrantes:

| **Nombre**                   | **Instituto/Organización** | **Email**             |
|------------------------------|----------------------------|-----------------------|
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
> - **Indicaciones** para una correcta implementación.
> - **Código funcional** específico para cada sensor.
>
> ### 2. Integración con ThingsBoard
> El repositorio incluye un archivo **main** que recopila las mediciones de todos los sensores y las envía a la plataforma **ThingsBoard** mediante el protocolo **MQTT**. Esto permite la monitorización en tiempo real de las variables.
>
> ### 3. Manual de uso y ensamblaje
> Además, el repositorio ofrece un manual detallado que cubre:
> - **Esquemas de conexión** y **diagramas eléctricos**.
> - **Instrucciones paso a paso** para el ensamblaje del DTHIS-C.
>
> 
> Este repositorio es útil tanto para trabajar con sensores de forma individual como para la construcción completa del dispositivo DTHIS-C.
