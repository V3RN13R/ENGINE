@echo off
@REM cls
@REM :: Vamos al directorio de dependencies para compilarlas
cd .\VERNIERENGINE\Dependencies

call  Dependecies.bat

@REM :: Una vez compiladas las dependencias pasamos a compilar nuestro motor como tal 
cd ..
msbuild "VERNIERENGINE.sln" /p:configuration=Debug /p:platform=x64
msbuild "VERNIERENGINE.sln" /p:configuration=Release /p:platform=x64
