
:: Abrir Developer Command Prompt para ejecutar este .bat

:: Primero tiene que construir el Motor
echo BUILDING MOTOR
cd Motor-Ola-Recu/MotorOla_Solution
::call MotorOla.bat
cd ../..

:: Despues tiene que generar Game.dll y Game.lib
echo BUILDING GAME
msbuild Zombis_Project.sln -p:Configuration=Debug
msbuild Zombis_Project.sln -p:Configuration=Release
echo BUILDING DONE

:: Ahora hay que mover Juego.dll a Motor-Ola/MotorOla_Solution/GameToLoad
cd DLL
copy /Y Juego.dll "../Motor-Ola-Recu/MotorOla_Solution/Exes/Juego.dll"
copy /Y Juego_d.dll "../Motor-Ola-Recu/MotorOla_Solution/Exes/Juego_d.dll"
echo JUEGO.DLL MOVIDO
cd ..

:: Y los Assets del Juego a Motor-Ola/MotorOla_Solution/Exes/Assets
xcopy /Y /s /i Assets "./Motor-Ola-Recu/MotorOla_Solution/Exes/Assets/"
echo ASSETS MOVIDOS

:: Pausa para ver que ha ocurrido
PAUSE >nul