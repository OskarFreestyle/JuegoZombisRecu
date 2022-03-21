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

:: Ahora hay que mover Juego.dll a Motor-Ola/MotorOla_Solution/GameToLoad

::echo JUEGO.DLL MOVIDO

:: Y los Assets del Juego a Motor-Ola/MotorOla_Solution/Exes/Assets

::echo ASSETS MOVIDOS

:: Pausa para ver que ha ocurrido
PAUSE >nul