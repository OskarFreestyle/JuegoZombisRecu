# How to use
> Trataré de explicar el proceso para montar toda el proyecto: motor + juego.
Este es el primer juego hecho en el Motor Ola.

## Steps:
1. Clone this repository to a local directory,  
    the easiest way is to use a shell like PowerShell 7 with GitHub CLI installed  
    and use the following command prompt:  
    ```gh repo clone GDV-Proyectos3/JuegoZombis```  
2. Then do the same step with the submodule that corresponds to the motor engine,  
    allocate at: https://github.com/GDV-Proyectos3/Motor-Ola  
    You can use the following command prompt:  
    ```gh repo clone GDV-Proyectos3/Motor-Ola```  
3. With the **Developer Command Prompt for VS 2019**  
    you have to build the dependencies of the motor engine *MotorOla*.  
    There two for open this tool:  
    - Inside of the MotorOla solution or JuegoZombis solution,  
      open the following path: ```tools\command line\system symbol for developers```  
    - Or look for it at the filesystem of the OS, in windows you can make a search  
      it would something like this: ```Developer Command Prompt for VS 2019```  
4. With this tool opened and going to the path of the ```MotorOla_Solution.sln```,  
    it would be something like this: ```PROYECTO\JuegoZombis\Zombis_Project\Motor-Ola\MotorOla_Solution```,  
    and then execute the automation tool: ```MotorOla.bat```  
5. With this done open ```MotorOla_Solution.sln```  
    and check that **App** project is marked as the startup project.  
6. Build the full ```MotorOla_Solution.sln``` or run the App project,  
    it would generate all the necessary files to run it and will run a *TestScene.lua*
7. Allright, we have the motor up to day! Now we need to build the game,  
    for that, at the ```Developer Command Prompt for VS 2019```  
    change the current directory to the ```Zombis_Project.sln``` path,  
    that would be something like this: ```PROYECTO\JuegoZombis\Zombis_Project```,
    and then execute the automation tool: ```GeneraJuegoSinCompilarMotor.bat```  
8. Now is completely everything ready to run and play! Have fun!  
9. Final step: open ```MotorOla_Solution.sln``` and run the **App project**.
