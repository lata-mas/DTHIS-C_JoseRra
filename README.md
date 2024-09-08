# TemplateSADs
Repositorio TEMPLATE para los otros dispositivos del IER. 
**Antes de usar esta plantilla se recomienda ver el video, si ya está familiarizado 
con Github y los repositorios en general, puede omitir esta información,**.

[**Video**](https://youtu.be/eMYjKd1Cey0)

##### Mientras trabaja con esta plantilla para crear un repositorio o mientras la use, puede seguir la lista de abajo para que vaya llevando un orden de lo que ha hecho y lo que aún le queda por hacer.

**En cuanto a la documentación, puede ser de ayuda para ver los archivos contenidos en este repositorio**

[**REPO DE EJEMPLO**](https://github.com/jwilliamsee/SensorH2OResidencia)

#  las casillas casillas no se pueden marcar, sólo es para visualización, para saber lo que debe tener la documentación de su dispositivo
- [ ] Lista de costos
- [ ] SRC completos
- [ ] Pictogramas
- [ ] Esquemático
- [ ] Diseño PCB
- [ ] Gerber PCB
- [ ] Lista materiales
- [ ] Planos CAD
- [ ] CAD
- [ ] STL
- [ ] Manual Operación
- [ ] Manual Ensamble
- [ ] Fichas Técnicas
- [ ] Doc. Errores y soluciones

**Cuando su repositorio se encuentre terminado, puede borrar esta parte y hacer una Check-List basado en lo de arriba, la intención es que sólo quede la información a partir que se termina este párrafo**


# Dispositivo 
**(nombre de su dispositivo)**
# 1.0 Introducción 
**(adaptar esta introducción a su dispositivo)**

El futuro de la humanidad y del planeta dependen de la manera en la que produzcamos energía: un sistema energético fiable, asequible y descarbonizado es fundamental.
Las energías renovables son fuentes de energía limpias, inagotables y crecientemente competitivas. Se diferencian de los combustibles fósiles principalmente en su diversidad, abundancia y potencial de aprovechamiento en cualquier parte del planeta, pero sobre todo en que no producen gases de efecto invernadero, causantes del cambio climático, ni emisiones contaminantes. Además, sus costes evolucionan a la baja de forma sostenida, mientras que la tendencia general de costes de los combustibles fósiles es la opuesta.
El crecimiento de las energías renovables es imparable, como queda reflejado en las estadísticas aportadas anualmente por la Agencia Internacional de la Energía (AIE): según las previsiones de la AIE, la participación de las renovables en el suministro eléctrico global pasará del 26% en 2018 al 44% en 2040, y proporcionarán 2/3 del incremento de demanda eléctrica registrado en este período, principalmente a través de las tecnologías eólica y fotovoltaica.
De acuerdo a la AIE, la demanda mundial de electricidad aumentará un 70% hasta 2040, elevando su participación en el uso de energía final del 18% al 24% en el mismo período, espoleada principalmente por regiones emergentes (India, China, África, Oriente Medio y el Sureste asiático).
Con lo anterior y compartiendo la idea de utilizar mas las energías limpias, se implementan nuevas formas de controlar los diferentes recursos que se utilizan en el día a día en el Instituto de Energías Renovables-UNAM, se implementarán dispositivos que puedan medir la cantidad de recursos que se consumen como lo son: el agua, la energía eléctrica, humedad, intensidad luminosa y temperatura de un edificio del instituto, con la intención de poder medir cada variable y posteriormente observar cuanto se consume para tratar de reducirlos en gran medida, lo anterior se lleva a cabo con dispositivos electrónicos que están integrados principalmente con sensores y haciendo uso de tecnologías abiertas para los códigos y envío de datos a la plataforma Thingsboard para la visualización de gráficos.

### 1.1 Sobre los autores
**(adaptar según los autores que participan)**

|Nombre|Instituto/Organización|Email|
| ------------ | ------------ | ------------ |
|Autor 1| | |
|Autor 2| | |
|Autor 3| | |
|Guillermo Barrios del Valle|IER-UNAM|gbv@ier.unam.mx|
|Guillermo Ramírez Zúñiga|IER-UNAM|guraz@ier.unam.mx|

------------

# 2. Alcance

**(adaptar a su dispositivo)**

El dispositivo **(nombre del dispositivo)** tiene como alcance, en esta etapa, contar con toda la documentación necesaria para ser replicado de manera eficaz y eficientemente, después de ser trabajado por un grupo de personas se espera que el proyecto tenga todo lo que se necesita para que otras personas puedan entender el funcionamiento y requisitos de operación.

La audiencia a la que está destinada es:

- Por el momento a personal del IER-UNAM que se encuentra trabajando en el proyecto "Edificios demostrativos de diseño bioclimático en clima cálido subhúmedo en el Instituto de Energías Renovables UNAM".
Proyecto número 291600 del Fondo de Sustentabilidad Energética.
- Compañeros que se interesen en aportar al proyecto para mejorar o para replicarlo directamente.

------------

# 3. Conceptos y definiciones

**(puede modificar esta parte o dejarlo así, porque aplica para todos los dispositivos)**

### 3.1 Saber como

Es necesario conocer algunas cosas antes de intentar entender muchos puntos del proyecto, como por ejemplo: lectura de planos electrónicos, diseño CAD, conocimiento medio de electrónica, programación, entre otras.

### 3.2 Diseño

Deberá manejar algún software de diseño por computadora, para modificar, replicar el diseño existente e incluso conocer la sección de ensamble de piezas en el software de su preferencia.

### 3.3 Hacer

Fabricar, construir, ensamblar, imprimir, configurar, programar y compilar códigos.

### 3.4 Open source

Por su traducción al español, "fuente abierta", durante el desarrollo del proyecto se busca que todos los programas a usar, sean de fuente abierta para evitar pagos costosos de Licencia, para cada necesidad existe un software de fuente abierta.

### 3.5 Thingsboard

Es una plataforma IOT que nos ayuda a visualizar gráficamente las variables que estamos midiendo para tener referencias de lo que se está haciendo.

### 3.6 Github

Plataforma web, que sirve como "bodega" para almacenar un proyecto con sus respectivas versiones o modificaciones que pueda sufrir durante el desarrollo, al mismo tiempo ayuda a documentar y a entender la estructura de su funcionamiento.

------------

# 4.0 Especificaciones de la estructura

### 4.1 Introducción

**(no modificar)**

En esta sección se encuentra la estructura general del proyecto, de forma que sea entendible y que se le pueda dar seguimiento para la lectura del mismo y entender que lleva un orden.
Esta forma de estructurar el proyecto es un formato estándar de Open Know-How, cabe mencionar que no es el ideal pero para entender de forma general un proyecto de electrónica es aceptable.
El almacenamiento en Github nos ayuda en todo momento a realizar modificaciones que creemos necesarias y sobre todo a tener control total de los cambios que va sufriendo el proyecto durante el desarrollo, si alguna no nos agrada o no es la correcta, podemos regresar sin ningún problema y dejarlo como antes.

### 4.2 Estructura

**(adaptarlo a su repositorio)**

### 4.2.1 Formato

El formato de archivo para la documentación del dispositivo **(nombre del dispositivo)** es Markdown por su facilidad de uso.
Algunos archivos están en formato PDF pero es necesario para una mejor visualización de los esquemas que se muestran en ese formato.

### 4.2.2 Nombre del archivo

Para los nombres de los archivos, es necesario que no se usen comas, virguililla o tilde de la ñ, las separaciones de las palabras pueden ser usadas con guiones o sin espacios, pero con una letra mayúscula para saber donde termina e inicia otra palabra, por ejemplo: ArchivoEstructura".
Las extensiones de los archivos pueden ser:

- .json | Para los archivos que se realizaron con EasyEDA.
- .md | Para los archivos que son creados en formato de texto Markdown, M Editor, DILLINGER e incluso el archivo README de Github.
- .fzz | Para los archivos que fueron creados en el software de Fritzing, pictogramas de conexiones.
- .ESTEP | Para los archivos de diseño CAD, que pueden ser visualizados en cualquier software de diseño, es formato general.
- .STL | Para los archivos de impresión, para que el diseño de la carcasa del dispositivo pueda ser visualizado al momento de imprimirlo en 3D.
- .zip | Para los archivos de impresión de la placa o PCB, están comprimidos porque son varios archivos.
- .PDF | Para los archivos que si se guardan en otro formato, posiblemente se moverían mucho las líneas, formas, tablas, imágenes, etc. Los archivos que se encontrarán en el repositorio en este formato serán los planos para el diseño de la carcasa.

### 4.2.3 Vínculos

En algunas secciones de la documentación es necesario nombrar o hacer referencias a rutas externas, pueden ser a imágenes, páginas web entre otras, simplemente se hace uso de los links originales de la web en cuestión, copiando y posteriormente pegando en la sección correspondiente para no tener que buscar de manera externa, deberán dejar espacios entre título o texto para que no existan errores de posición en el archivo de texto final.

#### 4.2.4 Ubicación del repositorio

El repositorio de todo el proyecto se encuentra en Github, las diferentes carpetas y archivos están alojadas en un un solo repositorio, no existe una carpeta raíz, pero sí existe una dirección raíz y es la siguiente:

![](pegar link)

[**Nombre del dispositivo**](pegar link)

### 4.3 Información de la web

La página de presentación del proyecto, está en la sección de Github.

El sitio web del formato estándar para documentar es el siguiente:

[README](pegar el link de su archivo Readme)

### 4.4 Propiedades descriptivas

### 4.4.1 Título

##### Dispositivo **(nombre del dispositivo)**
##### **(nombre del dispositivo)**

### 4.4.2 Descripción

##### Energías renovables
##### **(Descripción breve del dispositivo)

### 4.4.3 Uso previsto

##### Control de variable

**(adaptar información de su dispositivo)**

###### Informa al usuario el **(lo que mida)** de un lugar donde existe gran consumo del recurso, puede ser cuantificado para conocer exactamente en que momento se ha consumido mas y con base a esa información pueden aplicarse estrategias para mantener un consumo menor o aplicar ciertas medidas que ayuden a disminuirlo.

### 4.4.4 Palabras clave

##### **(actualizar)**
##### Electrónica
##### Dispositivo
##### Medidor de

### 4.4.5 Precauciones y recomendaciones

Son recomendaciones para operar el dispositivo **(nombre del dispositivo)**, pueden existir más, pero eso depende del usuario, pueden surgirle diferentes dudas, a unos más que a otros.
En este link hay algunos que pueden ayudar:

[ErroresYsoluciones](link del archivo .md)

### 4.5.6 Contacto primario

**Inv. A tiempo completo:** Dr. Guillermo Barrios del Valle

**Email:** gbv@ier.unam.mx



**Posdoc.:** Dr. Guillermo Ramírez Zúñiga

**Email:** guraz@ier.unam.mx

### 4.5.7 Colaboradores

**Nombre:** agregar aquí

**Instituto:** agregar aquí

**Email:** agregar aquí



**Nombre:** agregar aquí

**Instituto:** agregar aquí

**Email:** agregar aquí



**Nombre:** agregar aquí

**Instituto:** agregar aquí

**Email:** agregar aquí


### 4.5.7 Imagen

Representación gráfica del dispositivo H2O

![](link de la imagen aquí)

### 4.5.8 Etapa de desarrollo

La etapa en la que se encuentra el desarrollo del dispositivo **(nombre el dispositivo)**, es la de documentación, se espera que sea la penúltima etapa, para poder ser replicado de forma eficiente y eficaz.

### 4.5.9 Fue hecho físicamente

El dispositivo sí se ha hecho de forma práctica, es decir, se ha llevado a la práctica para comprobar el funcionamiento del mismo, solo como pruebas de funcionamiento, el dispositivo completo y funcionando durante largos períodos de tiempo no se ha realizado, falta montarlo completo, que mida con su respectiva carcasa de protección.

### 4.5.10 Se ha comprobado la documentación

La réplica del dispositivo usando la estructura aquí mostrada y siguiendo la documentación no se ha realizado, aún está en revisión de estructura de documentación y de archivos factibles para el desarrollo eficiente.

### 4.5.11 Estándares usados

El estándar de documentación completo, no se ha seguido, pero si se ha usado el estándar para esta documentación de Open Know-How, algunos puntos se han omitido porque al no ser la estructura para documentar proyectos electrónicos, existen puntos que salen sobrando o que definitivamente no aplican para este tipo de proyectos.
El link del estándar usado es el siguiente:

[EstandarOpenKnowHow](https://app.standardsrepo.com/MakerNetAlliance/OpenKnowHow/src/branch/master/1#a40dfa47-8bff-4e28-9338-3f808ddfe6ae)

### 4.6 Documentación

### 4.6.1 Punto de entrada de la documentación:

**(adapatar los siguientes puntos al contenido según el dispositivo)**

### Carpeta [CAD](agregar link de la carpeta aquí)

En la carpeta CAD se encuentran los archivos .STEP del diseño de la carcasa realizado, hasta el momento en SolidWorks, la carcasa está diseñada en 3 partes: 1. La base de la carcasa, 2. La base media y 3. La tapa, para poder visualizar éstos archivos es necesario tener instalado algún software de diseño.

En la misma carpeta se encuentran planos de la carcasa en formato PDF y los archivos .STL para visualización.

### Carpeta [Diagramas](agregar link de la carpeta aquí)

En la carpeta de Diagramas se encuentra el esquemático en .json, para visualizarlo o editarlo es necesario clonar el repo localmente, ir al software en versión online, sin crear cuenta, abrir el archivo desde la versión online.
También se encuentra el esquemático en PDF.

Se encuentran el dieño de PCB en .json, para editarlo es necesario abrirlo con el software EasyEDA, primero descargarlo y después abrirlo desde el software.

Para la representación gráfica de los componentes del dispositivo y conexión de los sensores, se encuentran los archivos con extensión .fzz, son los esquemas de conexión realizados en el software Open source Fritzing para conexiones de los sensores.

En la carpeta también se encuentra un archivo .zip con lo necesario para maquinar el pcb.

### Carpeta [Imagenes](agregar link de la carpeta aquí)

En esta carpeta están todas las imagenes que se usaron en los archivos de los manuales y otras imagenes necesarias para el complemento del dispositivo **(nombre del dispositivo)**, que en todas se mencionan en algún archivo existente en el repositorio.

### Carpeta [Manuales](agregar link de la carpeta aquí)

En esta carpeta se encuantran 3 archivos, 2 manuales y uno de errores:
1. El manual de operación, necesario consultarlo antes de iniciar con la réplica del dispositivo.
2. El manual de ensamble, de manera gráfica (ilustrativa), se describe de forma general como realizar el ensamble de los componentes del dispositivo.
3. El otro archivo tiene algunas sugerencias de operación del dispositivo **(nombre del dispositivo)**.

### Carpeta [Materiales](link de la carpeta aquí)

En la carpeta "Materiales" se encuentran dos archivos con extensión md y otros en PDF.
1. En el archivo Lista_de_materiales_H2O se encuentran los materiales que se necesitan para el pcb.
2. En el archivo ListaCostosH2O se encuentran los costos unitarios y total de los componentes.
3. Los archivos en PDF son hojas de datos de algunos componentes que se usan en el dipositivo H2O.

### Carpeta [SRC](link de la carpeta aquí)

En esta carpeta está el código para operar el dispositivo y códigos complementos necesarios del dispositivo.

### Archivo [ChecklistH2O](agregar link aquí)

En este archivo se encuentra en forma de lista los documentos que el dispositivo H2O debe tener para su correcta operación.

### Thingsboard

Dashboard del dispositivo H2O en la plataforma de Thingsboard:

**(nombre del dashboard en Thingsboard aquí)**

Las credenciales para tener acceso se deberán solicitar con alguno de los doctores.

La web (Dashboard) se encuantra aquí:

[**Nombre aquí**](link del dashboard creado en Thingsboard aquí)

------------

# 5.0 Bibliografía

[1] Open Know-How
https://app.standardsrepo.com/MakerNetAlliance/OpenKnowHow/src/branch/master/1#a40dfa47-8bff-4e28-9338-3f808ddfe6ae

[2] Github
https://github.com/

[3] EasyEDA
https://easyeda.com/editor

[4] Fritzing
https://fritzing.org/

[5] DILLINGER
https://dillinger.io/

[6] M Editor.md
https://pandao.github.io/editor.md/en.html

