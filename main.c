#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "./maze/maze.h"
#include "./utils/utils.h"
#include "./maze_loader/maze_loader.h"

int main(void) {
    // InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    // SetTargetFPS(30);
    //
    read_maze_file("./labirinto.txt");

    // int **testMaze = (int **) malloc(9 * sizeof(int *));
    // for (int i = 0; i < 9; i++) {
    //     testMaze[i] = (int *) malloc(9 * sizeof(int));
    // }

    // int tempMaze[9][9] = {
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {1, 2, 4, 0, 0, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1, 0, 0, 0, 1},
    //     {1, 0, 0, 0, 1, 0, 1, 0, 1},
    //     {1, 1, 1, 1, 1, 0, 1, 3, 1},
    //     {1, 1, 1, 1, 1, 0, 1, 1, 1},
    //     {1, 0, 0, 0, 0, 0, 0, 0, 1},
    //     {1, 1, 0, 1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1},
    // };

    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         testMaze[i][j] = tempMaze[i][j];
    //     }
    // }

    // Maze *gameMaze = new_maze(9, testMaze);

    // while (!WindowShouldClose()) {
    //     BeginDrawing();
    //         ClearBackground(BLACK);
    //         DrawMaze(gameMaze);
    //     EndDrawing();
    // }

    // CloseWindow();

    return 0;
}
