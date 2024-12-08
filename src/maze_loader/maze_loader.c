#include <stdio.h>
#include <stdlib.h>

#include "../maze/maze.h"
#include "../utils/utils.h"
#include "./maze_loader.h"

int read_maze_size(char *file_path) {
    FILE *maze_file = fopen(file_path, "r");
    if (maze_file == NULL) {
        printf("Erro: nao foi possivel encontrar o arquivo do labirinto");
        return -1;
    }

    int dimension;
    fscanf(maze_file, "%d", &dimension);
    fclose(maze_file);

    return dimension;
}

int** read_maze_blueprint(char *file_path, Maze *target_maze) {
    FILE *maze_file = fopen(file_path, "r");
    if (maze_file == NULL) {
        printf("Erro: nao foi possivel encontrar o arquivo do labirinto");
        return NULL;
    }

    int maze_size = maze_get_size(target_maze);
    printf("Maze size: %d\n", maze_size);
    if (maze_size <= 0) {
        printf("Erro: nao foi possivel obter o tamanho do labirinto");
        return NULL;
    }

    int **maze_blueprint = (int **) malloc(maze_size * sizeof(int *));
    if (maze_blueprint == NULL) alloc_error();

    fseek(maze_file, 1, SEEK_CUR); // Jump the first char
    if (maze_size >= 10) {
        fseek(maze_file, 1, SEEK_CUR); // Jump the sec char
    }

    for (int i = 0; i < maze_size; i++) {
        maze_blueprint[i] = (int *) malloc(maze_size * sizeof(int));
        if (maze_blueprint[i] == NULL) alloc_error();

        for (int j = 0; j < maze_size; j++) {
            fscanf(maze_file, "%d", &maze_blueprint[i][j]);
        }
    }

    fclose(maze_file);

    return maze_blueprint;
}
