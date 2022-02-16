# JuegoZombis (nombre provisional)
Este es el primer juego hecho en el Motor Ola
## Resumen
- **Género**: Twin Stick Shooter
- **Modos**: Un jugador / Arcade
- **Plataformas**: Pc - Teclado y ratón o Mando
- **Lenguaje de programación**: C++
- **Público objetivo:** Mayores de 13

## 0.- Descripción

Juego de disparos con vista top down que consiste en sobrevivir a oleadas de zombis consiguiendo la mayor puntuación posible. Podrá haber varios tipos de zombis con más vida, velocidad, etc. Al morir los zombis podrán soltar power ups. La dificultad aumentaría a medida que se avance de oleadas ya sea incrementando la vida de los zombis o el número de estos.

El juego se centrará especialmente en la jugabilidad, sin tener ninguna historia con trasfondo. Se conservan muchos aspectos típicos del género como el concepto del género cómo el movimiento, lógica de los zombis, armas, diseño de niveles...

La estética de momento serán cubitos.

Producido usando nuestro querido Motor Ola. Para más información consultar su repositorio. Recursos de momento no sabemos de donde sacarlos.

### 0.1.- Versiones del documento
- Versión 0.1 15/02/2022
    Los detalles incluidos de momento en este documento han sido sacado de la conversación que tuvimos un día, por tanto no tuvimos tiempo a especificar muchos de ellos y           cualquier cosa puede variar.

## 1.- Menús e interfaz
### 1.1.- Menú de inicio
El menú de inicio del juego consistirá en una pantalla donde se observarán los siguientes botones:

- **Jugar:** para empezar a jugar una nueva partida.
- **Records:** muestra los records que se tienen dentro del juego.
- **Controles:** muestra los controles, en principio no configurables.
- **Opciones:** muestra la pantalla de opciones, de momento solo sonido.
- **Salir:** para cerrar el juego.

#### 1.1.1.- Jugar
Iniciará una partida de 0. En principio no hemos hablado de guardado de partidas así que de momento siempre que empieces una partida tendrás que terminarla como en una máquina Arcade.

#### 1.1.2.- Records
Muestra un registro con las mejores puntuaciones.

#### 1.1.3.- Controles
Muestra los controles, en principio no configurables

#### 1.1.4.- Opciones
Muestra las opciones.

#### 1.1.5.- Salir
Sale del juego.

### 1.2.- Interfaz durante el *gameplay*
El HUD en pantalla estará compuesto por los siguientes elementos:

- **Vida:** muestra la vida restante del jugador. 
- **Puntuación:** indica los puntos obtenidos hasta el momento.

- **Oleada:** aquí estoy fantaseando porque no se ha especificado.
- **Contador de muertes:** lo mismo.

## 2.- Jugabilidad
La jugabilidad nos permitirá movernos en las 8 direcciones, disparando mientras tanto a cualquier otra dirección. Las balas serán infinitas (aunque es posible que tengamos que recargar cada cierto número de disparos). Los zombis que matemos dejarán caer power ups que recogeremos al pasar por encima y tendrán efectos únicos. Estos podrán ser nuevas armas o mejoras de arma temporales o permanentes y alguna que otra habilidad (aún por definir).

### 2.1.- Mecánicas
- **Click izquierdo:** Disparo (en la dirección a la que apunte el ratón).
- **WASD:** se utilizará para moverse, podrán combinarse para conseguir las 8 direcciones.
- **Tecla de pausa:** habilita el menú de pausa.

### 2.2.- Dinámicas

#### 2.2.1.- Objetivo principal
El objetivo conseguir sobrevivir más que nadie y entrar en el ranking de records.

#### 2.2.2. Ganar
El jugador no podrá ganar, todas las partidas acaban con la muerte del jugador.

## 3.-Contenido
### 3.1.- Historia
No tiene
   
## 4.Referencias

    Call of Duty Dead Ops Arcade
    

## 5.Bibliografía
