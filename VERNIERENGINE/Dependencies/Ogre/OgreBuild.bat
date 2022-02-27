@echo off
::Guardamos la direccion a los 3 directorios que necesitamos
set BuildPlace=.\build\x64
set DllsPlace=.\..\..\..\..\Exes\
set CompilePlace=..\..\Src

:: Creamos la carpeta build
mkdir %BuildPlace%
::Nos movemos aquí para que genere todo dentro de la carpeta build y no dentro de la carpeta ogre
cd %BuildPlace%
:: Creamos el proyecto y lo compilamos en debug y release
cmake -DOGRE_BUILD_RTSHADERSYSTEM_SHADERS:BOOL="1" -DOGRE_INSTALL_SAMPLES:BOOL="0" -DOGRE_BUILD_SAMPLES:BOOL="0" -DOGRE_BUILD_COMPONENT_BITES:BOOL="0" -DOGRE_BUILD_COMPONENT_RTSHADERSYSTEM:BOOL="1" -DOGRE_BUILD_PLUGIN_STBI="1" -DOGRE_BUILD_RENDERSYSTEM_GL="1" %CompilePlace%
msbuild "OGRE.sln" /p:configuration=Debug
msbuild "OGRE.sln" /p:configuration=Release

echo OGRE compilado
::Movemos las .dll a VernierEngine\Exes
XCOPY /y /s .\bin\debug\OgreMain_d.dll %DllsPlace%
XCOPY /y /s .\bin\release\OgreMain.dll %DllsPlace%

XCOPY /y /s .\bin\debug\OgreRTShaderSystem_d.dll %DllsPlace%
XCOPY /y /s .\bin\release\OgreRTShaderSystem.dll %DllsPlace%

XCOPY /y /s .\bin\debug\Codec_STBI_d.dll %DllsPlace%
XCOPY /y /s .\bin\release\Codec_STBI.dll %DllsPlace%

XCOPY /y /s .\bin\debug\RenderSystem_GL_d.dll %DllsPlace%
XCOPY /y /s .\bin\release\RenderSystem_GL.dll %DllsPlace%

XCOPY /y /s .\bin\debug\SDL2.dll %DllsPlace%
XCOPY /y /s .\bin\release\zlib.dll %DllsPlace%

cd ..\..
echo Dlls movidas