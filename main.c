#include <stdio.h>

#include "raylib.h"
#include "./maze/maze.h"
#include "./utils/utils.h"

int main(void) {

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    SetTargetFPS(60);

    int testMaze[9][9] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 3, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    Maze* gameMaze = new_maze(9, testMaze);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawMaze(gameMaze);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
