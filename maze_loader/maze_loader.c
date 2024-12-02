#include <stdio.h>
#include <stdlib.h>

void read_maze_file(char *file_path) {
    FILE *maze_file = fopen(file_path, "r");
    if (maze_file == NULL) {
        printf("Erro: nao foi possivel encontrar o arquivo do labirinto");
        return;
    }

    int dimension;
    fscanf(maze_file, "%d", &dimension);
    printf("Maze Dimension: %d\n", dimension);

    int **maze = (int **)malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++) {
        maze[i] = (int *)malloc(dimension * sizeof(int));
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            fscanf(maze_file, "%d", &maze[i][j]);
        }
    }

    printf("Maze:\n");
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    fclose(maze_file);
}
