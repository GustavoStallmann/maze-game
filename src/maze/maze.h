#ifndef MAZE_H
#define MAZE_H

typedef struct Maze Maze;

Maze* new_maze(char *maze_file);
int get_maze_size(Maze *maze);
void free_maze(Maze *maze);
void DrawMaze(Maze *maze);

#endif
