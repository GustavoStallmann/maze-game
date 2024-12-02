#ifndef MAZE_H
#define MAZE_H

typedef struct Maze Maze;

Maze* new_maze(int maze_size, int **mazeBlueprint);
void free_maze(Maze *maze);
void DrawMaze(Maze *maze);

#endif
