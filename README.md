# ENGINE

En este documento se recoge la información acerca del motor desarrollado por el grupo V3RN13R.
## **Motor**
El motor será capaz de aportar las funcionalidades básicas para que sea posible crear un juego 3D para ello el motor consta de distintos proyectos además de tener implementado el ECS (Entity-Component-System)

### **ECS**
Usaremos el patrón ECS (Entity-Component System), en el que las entidades son las piezas con las que se implementan comportamientos en nuestro motor. Cada entidad tiene por defecto un **Transform** (con posición, rotación y escala), y componentes relacionados con el Render: para la carga de mallas/imágenes, de las texturas….

Algunas entidades también poseerán componentes que hagan alusión a las mecánicas: un componente Movimiento para el personaje principal y las IA; un componente Disparo para que el jugador pueda disparar, etc.

Para la creación de prefabs se guardará un archivo con todos los componentes y la información relativa para iniciarlos y será el propio motor el que se encargue de crearla (a la entidad). 

Los componentes más importantes (como el encargado del render y el de físicas) estarán programados en el motor, pudiendo añadirse más componentes en las implementaciones específicas de cada juego. Para leer los componentes de archivo, primero se buscarán dentro de los generales del motor, y, en caso de que no se encuentren, se buscarán en los creados para el juego. De esta forma, nos resulta sencillo implementar la posibilidad de añadir componentes para los desarrolladores.
### **Escenas**
Tendremos una pila de escenas. El motor creará la escena principal del juego, y el juego se encargará de crear el resto de escenas cuando toque.
### **Proyectos**
#### **Render**
Usaremos la biblioteca Ogre3D, que nos proporciona todos los componentes para renderizar una escena en 3D: iluminación, cámaras, materiales, etc. 
#### **Audio**
Vamos a usar la API de FMOD, que nos da los componentes básicos para montar un sistema de audio estéreo.
#### **Físicas**
Como biblioteca de físicas usaremos Bullet, que es una biblioteca dinámica de detección de colisiones y rigid body.
#### **Lua**
Como lenguaje de scripting usaremos Lua. Además, Lua admite programación de procedimientos, programación orientada a objetos, programación funcional, programación basada en datos y descripción de datos.
#### **Interfaz**
Para la interfaz usaremos la biblioteca CEGUI, de la que usaremos componentes básicos como imágenes y botones.

## **Juego**
El juego será un archivo .dll que cargará el motor, se creará en una solución aparte y tendrá en principio un único proyecto que lo contendrá todo lo relacionado con el juego en sí. 

## **Proceso de desarrollo**
Como sistema de control de versiones se usará GitHub y como herramienta de gestión se usará PivotalTracker. Dentro de GitHub, para desarrollar en paralelo el motor y el juego, se hará uso del sistema de submódulos que posee, de manera que un repositorio puede contener otro repositorio distinto.

Para desarrollar el motor y el juego se ha decidido que se realizará en las siguientes fases:
### **Fase 1**
Una primera fase en la que se creará el proyecto de renderizado, y el proyecto de físicas, una vez creados estos proyectos se pasará realizar la compilación de las librerías necesarias para cada uno de estos dos proyectos, una vez compiladas se crearán los scripts necesarios en cada uno de los proyectos para disponer de las funcionalidades básicas, ya conseguido este paso se unirán ambos proyectos en el proyecto de unión o proyecto principal y se comprobará que funcionan correctamente, esto quiere decir sin errores en ejecución y sin dejar basura de manera que en caso de que esto suceda se sepa a qué nueva incorporación de código se debe.
### **Fase 2**
Una vez conseguido lo de la primera fase se procederá a ampliar las funcionalidades de ambos proyectos, también se creará el ECS, dando una gran importancia a la creación de  la componente Transform asegurándose de su correcto funcionamiento tanto en escalada como en rotación como en posicionamiento. Una vez conseguido se pasará a crear el proyecto de carga de datos y de interfaz con lo que esto corresponde.
### **Fase 3**
Tras la creación del ECS y de los nuevos proyectos para el motor solo quedaría la integración del proyecto de sonido. Esto se realizaría de forma paralela a la creación del juego.
### **Fase 4**
En ella se depurará todo, se programarán los últimos detalles restantes y se establecerán los assets definitivos.

## **Generación de contenido**
El pipeline de generación de contenido será el siguiente. Tomaremos como ejemplo el terreno. Diseñaremos el terreno en papel y pasaremos a Blender lo diseñado. Con un plugin exportamos a .mesh, formato que admite Ogre. El juego será el encargado de decirle al motor el .mesh que tiene que cargar, y este se encargará de renderizarlo.


# Informacion para desarrolladores

Aquí se encontrarán los enlaces para aquellos que requieran información sobre el funcionamiento de herramientas o funciones externas al motor.

## Bats
* [Dependencies.bat](https://github.com/V3RN13R/ENGINE/blob/main/DevelopersREADME/DependenciesBat.md) llamará a :

    * [*OgreBuild.bat*](https://github.com/V3RN13R/ENGINE/blob/main/DevelopersREADME/OgreBuildbat.md)

    * [*BulletBuild.bat*](https://github.com/V3RN13R/ENGINE/blob/main/DevelopersREADME/BulletBuildbat.md)

