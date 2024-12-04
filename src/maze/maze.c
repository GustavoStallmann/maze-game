#include "./maze.h"
#include "../utils/utils.h"
#include "../maze_loader/maze_loader.h"
#include <raylib.h>

struct Maze {
    int size;
    int **blocks;
    Stack *solution_path;
};

Maze* new_maze(char *maze_file) {
    int maze_size = read_maze_size(maze_file);
    if (maze_size <= 0) return NULL;

    Maze *maze = (Maze *) malloc(sizeof(Maze));
    if (maze == NULL) alloc_error();
    maze->size = maze_size;

    maze->blocks = read_maze_blueprint(maze_file, maze);
    maze->solution_path = new_stack();
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

    stack_free(maze->solution_path);
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
                    break;
                case VISITED_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, GREEN);
                    break;
            }
        }
    }
}

Vector2 maze_find_position(Maze *maze, Blocks type) {
    for (int i = 0; i <= maze->size; i++) {
        for (int j = 0; j <= maze->size; j++) {
            if (maze->blocks[i][j] == type) {
                return (Vector2) {i, j};
            }
        }
    }

    return (Vector2) {-1, -1};
}

int maze_set_block_type(Maze *maze, Vector2 block_pos, Blocks type) {
    int x = (int) block_pos.x;
    int y = (int) block_pos.y;
    int maze_size = get_maze_size(maze);

    if (maze_size < x || maze_size < y) return 1;

    maze->blocks[x][y] = type;
    return 0;
}

Blocks maze_get_block_type(Maze *maze, Vector2 block_pos) {
    int x = (int) block_pos.x;
    int y = (int) block_pos.y;

    Blocks block_type = maze->blocks[x][y];
    return block_type;
}

int maze_get_block_amount(Maze *maze, Blocks type) {
    if (maze == NULL || maze->blocks == NULL) return 0;

    int block_amount = 0;
    for (int i = 0; i < maze->size; i++) {
        if (maze->blocks[i] == NULL) continue;
        for (int j = 0; j < maze->size; j++) {
            if (maze->blocks[i][j] == type) {
                block_amount++;
            }
        }
    }

    return block_amount;
}

Stack* maze_get_solution_path(Maze *maze) {
    return maze->solution_path;
}

void maze_set_solution_path(Maze *maze, Vector2 *solution_path) {
    if (maze == NULL || solution_path == NULL) return;

    if (maze->solution_path) {
        stack_clear(maze->solution_path); // Clear any existing solution path
    }

    for (int i = 0; solution_path[i].x != 0 || solution_path[i].y != 0; i++) {
        stack_push(maze->solution_path, solution_path[i]);
    }
}