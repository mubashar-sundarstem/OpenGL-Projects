# OpenGL Breakout Game

This is a **Breakout-style 2D game** developed using **C++ and OpenGL**.  
It features ball-paddle mechanics, collision detection, and brick destruction, all implemented from scratch without external textures.

## Features

- Ball and paddle physics with reflection handling.
- Brick collision detection and removal.
- Wall and paddle boundary checks.
- Real-time rendering using modern OpenGL.
- Shaders written directly in the source code.

## Compilation

### Requirements:
- C++17 or higher
- GLFW
- GLAD
- GLM
- OpenGL 3.3 Core Profile

### Compile and Run:

```bash
g++ src/main.cpp src/glad.c -Iinclude -lglfw -ldl -o Breakout
./Breakout
