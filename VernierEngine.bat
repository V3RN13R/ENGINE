@echo off
@REM cls
@REM :: Vamos al directorio de dependencies para compilarlas
@REM cd .\VERNIERENGINE\Dependencies

@REM call  Dependecies.bat

@REM :: Una vez compiladas las dependencias pasamos a compilar nuestro motor como tal 
cd VERNIERENGINE
msbuild "VERNIERENGINE.sln" /p:configuration=Debug /p:platform=x64
msbuild "VERNIERENGINE.sln" /p:configuration=Release /p:platform=x64
