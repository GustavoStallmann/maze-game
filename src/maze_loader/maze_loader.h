#ifndef MAZE_LOADER_H
#define MAZE_LOADER_H
#include "../maze/maze.h"

int read_maze_size(char *file_path);
int** read_maze_blueprint(char *file_path, Maze *target_maze);

#endif
