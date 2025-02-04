#include <stdbool.h>
#include "raylib.h"
#include "maze_anim/maze_anim.h"
#include "./maze/maze.h"
#include "maze_solver/maze_solver.h"
#include "./utils/utils.h"
#include "./maze_anim/maze_anim.h"
#include "stack/stack.h"

int main(void) {
    SetTraceLogLevel(LOG_ERROR);

    Maze *game_maze = new_maze( );

    Vector2 *solve_order = maze_solve(game_maze);
    bool solution_setted = maze_set_solution_path(game_maze, solve_order);
    if (!solution_setted) {
        printf("Erro: nao foi possivel definir a solucao do labirinto\n");
        return 1;
    }
    maze_print_solution(game_maze);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    SetTargetFPS(60);

    Stack *track_maze_movements = new_stack();
    int frameCounter = 0;
    int framesPerAnim = 5;
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
