# Bullet bat

## ¿Qué hace?

El bulletBuild.bat se encargará de compilar el código de bullet tanto en release como en debug, como bullet no genera dlls no las mueve.

## ¿Cómo se ejecuta?

Para ejecutar este archivo se debe llamar desde una consola de comandos especial que es la "x64 Native Tools Command Prompt for VS 2019".
Una vez ejecutado el .bat desde esa consola se verá como salen muchas lineas algunas amarillas  no hay de que preocuparse.

## ¿Qué falta por hacer en este bat?
* Eliminar los proyectos de samples que a día de hoy dan problemas si se eliminan

* En este bat faltaria poner que la linea de bullet compilado salga solo si efectivamente no ha habido problemas