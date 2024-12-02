#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#include "./maze.h"
#include "../utils/utils.h"
#include "../maze_loader/maze_loader.h"

struct Maze {
    int size;
    int **blocks;
};

typedef enum {
    FREE_BLOCK = 0,
    WALL_BLOCK = 1,
    INITIAL_BLOCK = 2,
    TARGET_BLOCK = 3,
    ACTUAL_BLOCK = 4,
} Blocks;

Maze* new_maze(char *maze_file) {
    int maze_size = read_maze_size(maze_file);
    if (maze_size <= 0) return NULL;

    Maze *maze = (Maze *) malloc(sizeof(Maze));
    if (maze == NULL) alloc_error();
    maze->size = maze_size;

    maze->blocks = read_maze_blueprint(maze_file, maze);
    return maze;
}

int get_maze_size(Maze *maze) {
    return maze->size;
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
    // Vector2 current_pos = maze_find_current_position(maze);

}
