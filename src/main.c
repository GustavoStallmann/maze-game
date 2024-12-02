#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "./maze/maze.h"
#include "./utils/utils.h"

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    SetTargetFPS(30);

    char *maze_file = "./labirinto.txt";
    Maze *gameMaze = new_maze(maze_file);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawMaze(gameMaze);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
