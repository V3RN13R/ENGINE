@echo off
set dllsMoveTo=.\..\..\..\Exes

cd .\Lua

msbuild "Lua.sln" /p:configuration=Debug
msbuild "Lua.sln" /p:configuration=Release

echo Lua Compilado

::Movemos las .dll a la carpeta Exes
XCOPY /y /s .\x64\Debug\lua_d.dll %dllsMoveTo%
XCOPY /y /s .\x64\Release\lua.dll %dllsMoveTo%

echo Dlls movidas