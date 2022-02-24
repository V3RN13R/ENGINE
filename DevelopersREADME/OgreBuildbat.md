# Ogre bat

## ¿Qué hace?

El ogrebuild.bat se encargará de compilar el código de ogre tanto en release como en debug, y de mover las dlls generadas a la ruta que se le ha indicado, esta ruta esta puesta de manera relativa por lo que no afectará al ordenador en el que este, siempre y cuando la ruta no contenga ningun caracter especial ni sea demasiado larga.

## ¿Cómo se ejecuta?

Para ejecutar este archivo se debe llamar desde una consola de comandos especial que es la "x64 Native Tools Command Prompt for VS 2019".
Una vez ejecutado el .bat desde esa consola se verá como salen muchas lineas algunas amarillas otras rojas no hay problema de momento solo hay que comprobar que en las ultimas lineas se vea que pone que las dlls se han movido.

## ¿Qué falta por hacer en este bat?

En este bat faltaria poner que tanto la linea de ogre compilado como la de dlls movidas solo salgan si no ha dado problemas(más allá de los conocidos como son los 3 proyectos que no compilan en debug)