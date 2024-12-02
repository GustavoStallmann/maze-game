#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#include "maze.h"
#include "../utils/utils.h"

struct Maze {
    int size;
    int **blocks;
};

enum {
    FREE_BLOCK = 0,
    WALL_BLOCK = 1,
    INITIAL_BLOCK = 2,
    TARGET_BLOCK = 3,
    ACTUAL_BLOCK = 4,
} Blocks;

Maze* new_maze(int maze_size, int **mazeBlueprint) {
    if (maze_size <= 0) return NULL;

    Maze *new_maze = (Maze *) malloc(sizeof(Maze));
    if (new_maze == NULL) alloc_error();

    new_maze->blocks = (int **) malloc(sizeof(int *) * maze_size);
    if (new_maze->blocks == NULL) alloc_error();

    for (int i = 0; i < maze_size; i++) {
        new_maze->blocks[i] = (int *) malloc(sizeof(int) * maze_size);
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
    int blockSize = WINDOW_HEIGHT / maze->size;

    int mazeWidth = blockSize * maze->size;
    int xStart = WINDOW_WIDTH/2 - mazeWidth/2;
    int yStart = WINDOW_HEIGHT/2 - mazeWidth/2;

    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            int blockX = xStart + (i*blockSize);
            int blockY = yStart + (j*blockSize);
            int currentBlock = maze->blocks[i][j];

            switch (currentBlock) {
                case FREE_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                    break;
                case WALL_BLOCK:
                    DrawRectangle(blockX, blockY, blockSize, blockSize, DARKGRAY);
                    break;
                case INITIAL_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, RED);
                    break;
                case TARGET_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, GREEN);
                    break;
                case ACTUAL_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                    DrawCircle(blockX+blockSize/2, blockY+blockSize/2, (float) blockSize/4, PURPLE);
            }
        }
    }
}

static Vector2 maze_find_current_position(Maze *maze) {
    for (int i = 0; i <= maze->size; i++) {
        for (int j = 0; j <= maze->size; j++) {
            if (maze->blocks[i][j] == ACTUAL_BLOCK) {
                return (Vector2) {i, j};
            }
        }
    }

    return (Vector2) {-1, -1};
}

void maze_solve(Maze *maze) {
    Vector2 current_pos = maze_find_current_position(maze);
    Maze *aux_maze = new_maze(maze->size, maze->blocks);

}
