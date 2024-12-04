#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "maze_anim/maze_anim.h"
#include "./maze/maze.h"
#include "maze_solver/maze_solver.h"
#include "./utils/utils.h"
#include "stack/stack.h"

int main(void) {
    char *maze_file = "./labirinto.txt";
    Maze *game_maze = new_maze(maze_file);
    Vector2 *solve_order = maze_solve(game_maze);
    maze_set_solution_path(game_maze, solve_order);

    // Stack *solution_path = maze_get_solution_path(game_maze);
    // stack_print(solution_path);

    // InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    // SetTargetFPS(30);
    // while (!WindowShouldClose()) {
    //     BeginDrawing();
    //         ClearBackground(BLACK);
    //         DrawMaze(game_maze);
    //     EndDrawing();
    // }
    // free_maze(game_maze);
    // CloseWindow();
    return 0;
}
