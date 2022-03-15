:: Primero tiene que construir el Motor
echo BUILDING MOTOR
cd Motor-Ola/MotorOla_Solution
REM call MotorOla.bat
cd ../..

:: Despues tiene que generar Game.dll y Game.lib
echo BUILDING GAME
msbuild Zombis_Project.sln -p:Configuration=Debug
msbuild Zombis_Project.sln -p:Configuration=Release

echo BUILDING DONE

:: Pausa para ver que ha ocurrido
PAUSE >nul