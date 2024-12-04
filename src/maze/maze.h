#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "../stack/stack.h"

typedef enum {
    FREE_BLOCK     = 0,
    WALL_BLOCK     = 1,
    INITIAL_BLOCK  = 2,
    TARGET_BLOCK   = 3,
    ACTUAL_BLOCK   = 4,
    VISITED_BLOCK  = 5
} Blocks;

typedef struct Maze Maze;

Maze* new_maze(char *maze_file);
int get_maze_size(Maze *maze);
void free_maze(Maze *maze);
void DrawMaze(Maze *maze);
Vector2 maze_find_position(Maze *maze, Blocks position);
int maze_get_block_amount(Maze *maze, Blocks type);
Blocks maze_get_block_type(Maze *maze, Vector2 block_pos);
void maze_set_solution_path(Maze *maze, Vector2 *solution_path);
Stack* maze_get_solution_path(Maze *maze);
int maze_set_block_type(Maze *maze, Vector2 block_pos, Blocks type);

#endif
