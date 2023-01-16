# Snake game (in C)
This is a simple snake game written in C.
It uses the SDL2 library for graphics and input.
It doesn't check for the snake collision with itself, yet.

## How to run
You need to have SDL2, Cmake, Clang and Git installed on your system.
```bash
$ git clone https://github.com/Vaksoa/Snake-C.git
$ cd Snake-C
$ cmake .
$ make
```

## Potential improvements
- [ ] Check for snake collision with itself
- [ ] Add more game logic (e.g. score, game over, etc.)
- [ ] Add a UI (e.g. main menu, pause, etc.)
- [ ] Performance improvements (for experience and fun)
  - [x] Improve the input handling
  - [x] Use linked lists instead of arrays
  - [ ] Use 2D arrays for storing the game state
  - [ ] Use separate threads for logic and rendering
  - [ ] Use spatial partitioning for collision detection
  - [ ] Fix flickering and tearing by using double buffering