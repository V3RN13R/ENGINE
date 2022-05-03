@echo off

cd .\Ogre\
call OgreBuild.bat
::Al terminar el OgreBuildbat se encuentra en dependecies\ogre por lo que desplazamos una atras y entramos en bullet
cd ..\Bullet\
call BulletBuild.bat
::Al terminar el OgreBuildbat se encuentra en dependecies\bullet por lo que desplazamos una atras
cd ..\Lua\
call LuaBuild.bat
cd ..\..\Fmod\
call build.bat
cd ..