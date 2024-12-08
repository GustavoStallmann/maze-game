#include <stdbool.h>
#include "raylib.h"
#include "maze_anim/maze_anim.h"
#include "./maze/maze.h"
#include "maze_solver/maze_solver.h"
#include "./utils/utils.h"
#include "./maze_anim/maze_anim.h"
#include "stack/stack.h"

int main(void) {
    char *maze_file = "./labirinto.txt";
    Maze *game_maze = new_maze(maze_file);
    maze_print_maze(game_maze);

    Vector2 *solve_order = maze_solve(game_maze);
    bool solution_setted = maze_set_solution_path(game_maze, solve_order);
    if (!solution_setted) {
        printf("Erro: nao foi possivel definir a solucao do labirinto");
        return 1;
    }
    Stack *track_maze_movements = new_stack();

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    SetTargetFPS(60);

    int frameCounter = 0;
    int framesPerAnim = 20;
    while (!WindowShouldClose()) {
        if (frameCounter >= framesPerAnim) {
            maze_anim(game_maze, track_maze_movements);
            frameCounter = 0;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            DrawMaze(game_maze);
        EndDrawing();
        frameCounter++;
    }

    maze_free(game_maze);
    CloseWindow();
    return 0;
}
