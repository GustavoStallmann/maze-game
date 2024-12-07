#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "raylib.h"
#include "../maze/maze.h"
#include "../stack/stack.h"
#include "../utils/utils.h"

typedef enum {
    UP,
    DOWN,
    RIGHT,
    LEFT
} Moves;

Vector2* maze_solve(Maze *maze);

#endif
