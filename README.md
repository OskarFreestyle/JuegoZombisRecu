# ** ZOMBIES PROJECT **
Este es el primer juego hecho en el Motor Ola

## Resumen
- **Género**: Twin Stick Shooter
- **Modos**: Un jugador / Arcade
- **Plataformas**: Pc - Teclado y ratón
- **Lenguaje de programación**: C++
- **Público objetivo:** Mayores de 7

## 1.- Descripción

JuegoZombis es un juego del genero Twin-Stick Shooter para un jugador en el que este tendrá que sobrevivir oleadas de zombis que se volverán más difíciles cada vez que el jugador logre matar a todos los zombis de la oleada actual. El jugador obtendrá puntos por cada zombi que mate. La partida terminará cuando el jugador es derrotado por los zombis y se le mostrará la puntuación total que ha obtenido y el top 5 records. 

El juego usa una perspectiva top-view que permite ver todo el area de juego y se podrán distinguir todos los elementos de la partida facilmente. 

El área de juego es un mapa cuadrado que tendra en cada esquina una zona donde pueden aparecer los zombis.

Los zombis corren hacia el jugador y, si se acercan lo suficiente a él, le harán daño hasta el punto de matarlo. El número de zombis aumentará por cada oleada que pase hasta que los zombis logren matar al jugador.

Producido usando nuestro querido Motor Ola. Para más información consultar su repositorio.

## 2.- Menús e interfaz
### 2.1.- Menú de inicio
El menú de inicio del juego consistirá en una pantalla donde se observarán los siguientes botones:

- **Jugar:** empieza una nueva partida.
- **Opciones:** muestra la pantalla de opciones, que de momento solo permite ajustar el sonido.
- **Salir:** cierra el juego.

<p align="center">
  <img src="https://github.com/OskarFreestyle/JuegoZombisRecu/blob/main/ImagenesMarkdown/Menu.png">
</p>

### 2.2.- Interfaz durante el *gameplay*
El HUD en pantalla estará compuesto por los siguientes elementos:

- **Vida:** muestra los corazones que le quedan al jugador. Pierde al quedarse sin ninguno.
- **Puntuación:** indica los puntos obtenidos hasta el momento.
- **Ronda:** presenta el número de la ronda actual.
- **Salir:** acaba la partida con el mismo efecto que si hubieras muerto.

<p align="center">
  <img src="https://github.com/OskarFreestyle/JuegoZombisRecu/blob/main/ImagenesMarkdown/Play.png">
</p>

### 2.3.- Menú de opciones
A este menú se podra acceder al desde el menú principal, dando al botón de opciones. Tiene los siguientes elementos:

- **Volumen:** botón que activa/desactiva el audio del juego.
- **Atrás:** se regresa al menú principal.

<p align="center">
  <img src="https://github.com/OskarFreestyle/JuegoZombisRecu/blob/main/ImagenesMarkdown/Opciones.png">
</p>

### 2.4.- Fin de la partida
Aqui se mostrará la puntuacion que ha obtenido el jugador en la partida y el top 5 records. El jugador podrá introducir 3 letras para guardar el record bajo un pseudónimo. Abajo hay un boton para regresar al menú principal.

<p align="center">
  <img src="https://github.com/OskarFreestyle/JuegoZombisRecu/blob/main/ImagenesMarkdown/Records.png">
</p>

### 2.5.- Diagrama de flujo de pantallas

<p align="center">
  <img src="https://github.com/OskarFreestyle/JuegoZombisRecu/blob/main/ImagenesMarkdown/FlujoPantallas.png">
</p>

## 3.- Jugabilidad
La jugabilidad nos permitirá movernos en las 8 direcciones, disparando mientras tanto a cualquier otra dirección y las balas serán infinitas. La partida acabará cuando al jugador no le queden vidas.

### 3.1.- Mecánicas
- **Click izquierdo:** disparo de un proyectil en la dirección a la que apunte el ratón.
- **WASD:** se utilizará para moverse, podrán combinarse para conseguir las 8 direcciones.

### 3.2.- Dinámicas
#### 3.2.1.- Objetivo principal
El objetivo consiste en sobrevivir el mayor número de oleadas posible y obtener la mejor puntuacion para batir el record anterior.

#### 3.2.2. Ganar
El jugador no podrá ganar, ya que todas las partidas acaban con la muerte del jugador.  
Solo es posible superar la puntuación máxima obtenida en partidas anteriores.

## 4.-Contenido
### 4.1.- Enemigos
Los zombis tendran diferentes modelos pero seguirán siendo el mismo tipo de enemigo que perseguira al jugador hasta que logre matarle o que le elimine este. 
Cuando el jugador elimina a todos los zombis de la oleada actual, comenzará la siguiente oleada en la que aparecerán un mayor número de zombis que en la anterior ronda.

Hay 3 tipos de zombis:
- **Zombie normal:** te persigue y te golpea. Muere de 1 disparo.
- **Zombie rápido:** es más pequeño. Te persigue muy rápido y te golpea. Muere de 1 disparo.
- **Zombie fuerte:** es más grande. Te persigue muy despacio y te golpea. Muere de 5 disparos.

### 4.2.- Escenarios

El juego posee un único escenario, que consiste en una "habitación" de 4 paredes con un suelo sobre el cual se desarrolla la acción.  

## 5.Referencias

* Call of Duty Dead Ops Arcade
* Boxhead zombies
