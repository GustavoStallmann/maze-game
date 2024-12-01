#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#include "maze.h"
#include "../utils/utils.h"

struct Maze {
    int size;
    int **blocks;
};

Maze* new_maze(int maze_size, int mazeBlueprint[maze_size][maze_size]) {
    if (maze_size <= 0) return NULL;

    Maze *new_maze = (Maze *) malloc(sizeof(Maze));
    if (new_maze == NULL) alloc_error( );

    new_maze->blocks = (int **) malloc(sizeof(int *) * maze_size);

    for (int i = 0; i < maze_size; i++) {
        new_maze->blocks[i] = malloc(sizeof(int) * maze_size);
        if (new_maze->blocks[i] == NULL) alloc_error();

        for (int j = 0; j < maze_size; j++) {
            new_maze->blocks[i][j] = mazeBlueprint[i][j];
        }
    }

    new_maze->size = maze_size;
    return new_maze;
}

void free_maze(Maze *maze) {
    if (maze == NULL) return;

    for (int i = 0; i < maze->size; i++) {
        free(maze->blocks[i]);
    }

    free(maze->blocks);
    free(maze);
}

void DrawMaze(Maze *maze) {
    int blockSize = (WINDOW_WIDTH/WINDOW_HEIGHT) * 20;

    int mazeWidth = blockSize*maze->size;
    int xStart = WINDOW_WIDTH/2 - mazeWidth/2;
    int yStart = WINDOW_HEIGHT/2 - mazeWidth/2;

    for (int i = 0; i <= maze->size; i++) {
        for (int j = 0; j <= maze->size; j++) {
            int blockX = xStart + (i*blockSize);
            int blockY = yStart + (j*blockSize);
            int currentBlock = maze->blocks[i][j];
            printf("%d", currentBlock);

            switch (currentBlock) {
                case 0:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                case 1:
                    DrawRectangle(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                case 2:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, RED);
                case 3:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, GREEN);
            }
        }
    }
}
