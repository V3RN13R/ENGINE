@echo off
::Guardamos la direccion a los 3 directorios que necesitamos
set BuildPlace=.\Build\x64
set DllsPlace=.\..\..\..\..\Exes\
set CompilePlace=..\..\Src

:: Creamos la carpeta build
mkdir %BuildPlace%
::Nos movemos aquí para que genere todo dentro de la carpeta build y no dentro de la carpeta ogre
cd %BuildPlace%

:: Creamos el proyecto y lo compilamos en debug y release
::cmake -DBUILD_CPU_DEMOS:BOOL="0" -DBUILD_BULLET2_DEMOS:BOOL="0" -DBUILD_OPENGL3_DEMOS:BOOL="0" -DUSE_MSVC_RUNTIME_LIBRARY_DLL:BOOL="1" %CompilePlace%
cmake -DUSE_MSVC_RUNTIME_LIBRARY_DLL:BOOL="1" %CompilePlace%
msbuild "BULLET_PHYSICS.sln" -p:configuration=Debug /maxcpucount
msbuild "BULLET_PHYSICS.sln" -p:configuration=Release /maxcpucount


cd ..\..
echo BULLET compilado