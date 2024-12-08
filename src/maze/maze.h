#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

Maze* new_maze();
void  DrawMaze(Maze *maze);
void  maze_print(Maze *maze);
void  maze_print_solution(Maze *maze);
bool  maze_remove_next_solution_step(Maze *maze);
bool  maze_free(Maze *maze);


int      maze_get_block_amount(Maze *maze, Blocks type);
int      maze_get_size(Maze *maze);
Blocks   maze_get_block_type(Maze *maze, Vector2 block_pos);
Stack*   maze_get_solution_path(Maze *maze);
Vector2  maze_get_next_solution_step(Maze *maze);
Vector2  maze_get_block(Maze *maze, Blocks position);
int      maze_get_solution_size(Maze *maze);


bool maze_set_size(Maze *maze, int size);
bool maze_set_solution_size(Maze *maze, int solution_size);
bool maze_set_block_type(Maze *maze, Vector2 block_pos, Blocks type);
bool maze_set_solution_path(Maze *maze, Vector2 *solution_path);
bool maze_set_actual_block(Maze *maze, Vector2 new_actual);

#endif
