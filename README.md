# Classic Snake Game

## Overview
This project is a simple implementation of the classic Snake game using the C programming language. The objective of the game is to maneuver a snake so that it eats the frog (food) which appears at random positions on the game field. Each time the snake eats a frog, it grows in length, and the game becomes progressively harder as the speed increases.

## Features
- Classic Snake game mechanics.
- Random frog (food) generation.
- Growing snake upon eating the frog.
- Continuous movement with directional controls.
- Game over condition when the snake collides with itself.

## Game Controls
- <span style="color:green; font-weight:bold;">w</span> : Move up
- <span style="color:red; font-weight:bold;">a</span> : Move left
- <span style="color:blue; font-weight:bold;">s</span> : Move down
- <span style="color:yellow; font-weight:bold;">d</span> : Move right

## Getting Started

### Prerequisites
To compile and run this game, you need:
- A C compiler (GCC recommended)
- Windows operating system (for `conio.h` and `windows.h`)

### Compilation
Compile the game using GCC:
```sh
gcc snake_game.c -o snake_game
