#include <stdio.h>
#include <stdlib.h>

#include "../maze/maze.h"
#include "../utils/utils.h"
#include "./maze_loader.h"

int** read_maze_blueprint(Maze *target_maze) {
    int maze_size;
    scanf("%d", &maze_size);
    maze_set_size(target_maze, maze_size);
    if (maze_size <= 0) {
        printf("Erro: nao foi possivel obter o tamanho do labirinto");
        return NULL;
    }

    int **maze_blueprint = (int **) malloc(maze_size * sizeof(int *));
    if (maze_blueprint == NULL) alloc_error();

    for (int i = 0; i < maze_size; i++) {
        maze_blueprint[i] = (int *) malloc(maze_size * sizeof(int));
        if (maze_blueprint[i] == NULL) alloc_error();

        for (int j = 0; j < maze_size; j++) {
            int value;
            scanf("%d", &value);
            maze_blueprint[i][j] = value;
        }
    }

    return maze_blueprint;
}
