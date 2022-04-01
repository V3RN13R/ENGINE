@echo off
set buildDir=.\
set dllsMoveTo=.\..\..\Exes

::Movemos las .dll a VERNIERENGINE
XCOPY /y /s fmod.dll %dllsMoveTo%
XCOPY /y /s fmodL.dll %dllsMoveTo%

echo FMOD "compilado"