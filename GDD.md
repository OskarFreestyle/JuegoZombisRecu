# 'JuegoZombis'
Este es el primer juego hecho en el Motor Ola
## Resumen
- **Género**: Twin Stick Shooter
- **Modos**: Un jugador / Arcade
- **Plataformas**: Pc - Teclado y ratón o Mando
- **Lenguaje de programación**: C++
- **Público objetivo:** Mayores de 13

## 1.- Descripción

Juego de disparos con vista cenital que consiste en sobrevivir a oleadas de zombis consiguiendo la mayor puntuación posible. Existen varios tipos de zombis con mayor vida, velocidad, etc. Al morir, los zombis podrán soltar power-ups. La dificultad aumenta a medida que se vencen oleadas, ya sea incrementando la vida de los enemigos o el número de estos.

El juego se centra especialmente en la jugabilidad, sin tener ningún trasfondo histórico. Se conservan muchos aspectos típicos del género como el concepto del movimiento, lógica de los zombis, armas, diseño de niveles...

La estética será de momento algo simplista.

Producido usando nuestro querido Motor Ola. Para más información consultar su repositorio.

### 1.1.- Versiones del documento
- Versión 0.1 15/02/2022
    Los apartados incluidos en este documento han sido extraídos de las primeras reuniones del equipo, y por lo tanto no ha habido tiempo para especificarlos en mucho detalle, quedando cualquier aspecto sujeto a posibles cambios.
- Versión 0.2 22/02/2022
    Precisión del contenido y arreglos; presentación al profesor.

## 2.- Menús e interfaz
### 2.1.- Menú de inicio
El menú de inicio del juego consistirá en una pantalla donde se observarán los siguientes botones:

- **Jugar:** empieza una nueva partida.
- **Récords:** muestra las puntuaciones más altas obtenidas por los distintos usuarios en el juego.
- **Controles:** muestra los controles, que no son configurables.
- **Opciones:** muestra la pantalla de opciones, que de momento solo permite ajustar el sonido.
- **Salir:** cierra el juego.

#### 2.1.1.- Jugar
Inicia una partida desde el principio. Siempre que comience una partida será necesario terminarla como en una máquina recreativa Arcade, no siendo posible el guardado del estado para retomarla posteriormente.

#### 2.1.2.- Récords
Muestra un registro con las mejores puntuaciones.

#### 2.1.3.- Controles
Muestra los controles, no configurables.

#### 2.1.4.- Opciones
Muestra las opciones.

#### 2.1.5.- Salir
Sale del juego.

### 2.2.- Interfaz durante el *gameplay*
El HUD en pantalla estará compuesto por los siguientes elementos:

- **Vida:** muestra la vida restante del jugador. 
- **Puntuación:** indica los puntos obtenidos hasta el momento.
- **Número de oleada:** presenta el número de oleadas superadas hasta el momento.
- **Contador de muertes:** indica el número de enemigos derrotados.

## 3.- Jugabilidad
La jugabilidad nos permitirá movernos en las 8 direcciones, disparando mientras tanto a cualquier otra dirección. Las balas serán infinitas (aunque es posible que tengamos que recargar cada cierto número de disparos). Los zombis que matemos dejarán caer power-ups que recogeremos al pasar por encima y tendrán efectos únicos. Estos podrán ser nuevas armas o mejoras de arma temporales o permanentes y alguna que otra habilidad.

### 3.1.- Mecánicas
- **Click izquierdo:** disparo de un proyectil en la dirección a la que apunte el ratón.
- **WASD:** se utilizará para moverse, podrán combinarse para conseguir las 8 direcciones.
- **Escape:** habilita el menú de pausa.

### 3.2.- Dinámicas

#### 3.2.1.- Objetivo principal
El objetivo consiste en sobrevivir el mayor tiempo posible y entrar en el ranking de máximas puntuaciones.

#### 3.2.2. Ganar
El jugador no podrá ganar, ya que todas las partidas acaban con la muerte del jugador.
Solo es posible superar la puntuación de jugadores anteriores.

## 4.-Contenido
### 4.1.- Enemigos

- Zombi básico: salud media, velocidad media, daño medio, color estándar
- Zombi pesado: salud alta, velocidad baja, daño alto, color oscuro
- Zombi veloz:  salud baja, velocidad alta, daño bajo, color claro

### 4.2.- Escenarios

El juego posee un único escenario, que consiste en una "habitación" de 4 paredes con un suelo sobre el cual se desarrolla la acción en 2D.
En este entorno se sitúan un número de pilares de forma aleatoria cada vez que se inicia el juego, que son obstáculos físicos para el jugador y sus enemigos.

### 4.3.- Potenciadores

- Potenciador de daño:      aumenta el daño de los proyectiles del jugador
- Potenciador de disparo:   aumenta el 'ratio' de disparo del jugador
- Potenciador de salud:     permite curar algo de salud al jugador
- Puntos extra:             otorga una considerable cantidad de puntos de bonificación
   
## 5.Referencias
´´´
* Call of Duty Dead Ops Arcade
* Boxhead zombies
´´´
