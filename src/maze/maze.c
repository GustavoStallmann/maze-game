#include "./maze.h"
#include "../utils/utils.h"
#include "../maze_loader/maze_loader.h"

struct Maze {
    int size;
    int **blocks;
    Stack *solution_path;
    int solution_size;
};

Maze* new_maze(char *maze_file) {
    int maze_size = read_maze_size(maze_file);
    if (maze_size <= 0) return NULL;

    Maze *maze = (Maze *) malloc(sizeof(Maze));
    if (maze == NULL) alloc_error();
    maze->size = maze_size;

    maze->blocks = read_maze_blueprint(maze_file, maze);
    maze->solution_path = new_stack();
    maze->solution_size = -1;
    return maze;
}

int maze_get_size(Maze *maze) {
    return maze->size;
}

bool maze_free(Maze *maze) {
    if (maze == NULL) return false;

    for (int i = 0; i < maze->size; i++) {
        free(maze->blocks[i]);
    }

    stack_free(maze->solution_path);
    free(maze->blocks);
    free(maze);
    return true;
}

void DrawMaze(Maze *maze) {
    int blockSize = WINDOW_HEIGHT / maze->size;
    float circleSize = (float) blockSize / 4;

    int mazeWidth = blockSize * maze->size;
    int xStart = WINDOW_WIDTH/2 - mazeWidth/2;
    int yStart = WINDOW_HEIGHT/2 - mazeWidth/2;

    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            int blockX = xStart + (i*blockSize);
            int blockY = yStart + (j*blockSize);
            int currentBlock = maze->blocks[j][i];

            switch (currentBlock) {
                case FREE_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                    break;
                case WALL_BLOCK:
                    DrawRectangle(blockX, blockY, blockSize, blockSize, BLACK);
                    break;
                case INITIAL_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, RED);
                    break;
                case TARGET_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, GREEN);
                    break;
                case ACTUAL_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, LIGHTGRAY);
                    DrawCircle(blockX+blockSize/2, blockY+blockSize/2, circleSize, BLUE);
                    break;
                case VISITED_BLOCK:
                    DrawRectangleLines(blockX, blockY, blockSize, blockSize, WHITE);
                    DrawCircle(blockX+blockSize/2, blockY+blockSize/2, circleSize/4, WHITE);
                    break;
            }
        }
    }
}

Vector2 maze_get_block(Maze *maze, Blocks type) {
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            if (maze->blocks[i][j] == type) {
                return (Vector2) {i, j};
            }
        }
    }

    return (Vector2) {-1, -1};
}

bool maze_set_block_type(Maze *maze, Vector2 block_pos, Blocks type) {
    int x = (int) block_pos.x;
    int y = (int) block_pos.y;
    if (maze->blocks == NULL || maze->blocks[x] == NULL) return false;

    int maze_size = maze_get_size(maze);
    if (x < 0 || y < 0 || x >= maze_size || y >= maze_size) return false;

    maze->blocks[x][y] = type;
    return true;
}

Blocks maze_get_block_type(Maze *maze, Vector2 block_pos) {
    int x = (int) block_pos.x;
    int y = (int) block_pos.y;

    Blocks block_type = maze->blocks[x][y];
    return block_type;
}

bool maze_set_actual_block(Maze *maze, Vector2 new_actual) {
    if (maze == NULL || maze->blocks == NULL) return false;

    Vector2 actual_block = maze_get_block(maze, ACTUAL_BLOCK);
    if (actual_block.x >= 0 && actual_block.y >= 0) {
        maze_set_block_type(maze, actual_block, VISITED_BLOCK);
    }

    if (maze_set_block_type(maze, new_actual, ACTUAL_BLOCK) != 0) return false;
    return true;
}

int maze_get_block_amount(Maze *maze, Blocks type) {
    if (maze == NULL || maze->blocks == NULL) return -1;

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

bool maze_set_solution_path(Maze *maze, Vector2 *solution_path) {
    if (maze == NULL || solution_path == NULL) return false;

    if (maze->solution_path) {
        stack_clear(maze->solution_path); // Clear any existing solution path
    }

    int solution_size = maze_get_solution_size(maze);
    if (solution_size <= 0) return false;

    for (int i = 0; i < solution_size; i++) {
        stack_push(maze->solution_path, solution_path[i]);
    }

    return true;
}

bool maze_set_solution_size(Maze *maze, int solution_size) {
    if (maze == NULL) return false;
    if (solution_size < 0) return false;

    maze->solution_size = solution_size;
    return true;
}

int maze_get_solution_size(Maze *maze) {
    return maze->solution_size;
}

Vector2 maze_get_next_solution_step(Maze *maze) {
    Vector2 next_step;
    int popped_value = stack_pop(maze->solution_path, &next_step);
    if (!popped_value) return (Vector2) {-1, -1};

    return next_step;
}

void maze_print_maze(Maze *maze) {
    printf("\n");
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            printf("[%d]", maze->blocks[i][j]);
        }
        printf("\n");
    }
}

void maze_print_solution(Maze *maze) {
    printf("Solucao do labirinto: \n");
    stack_print(maze->solution_path);
}
