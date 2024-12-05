#include "raylib.h"
#include "maze_anim/maze_anim.h"
#include "./maze/maze.h"
#include "maze_solver/maze_solver.h"
#include "./utils/utils.h"
#include "./maze_anim/maze_anim.h"

int main(void) {
    char *maze_file = "./labirinto.txt";
    Maze *game_maze = new_maze(maze_file);
    maze_print_maze(game_maze);

    Vector2 *solve_order = maze_solve(game_maze);
    maze_set_solution_path(game_maze, solve_order);

    maze_anim(game_maze);
    maze_print_maze(game_maze);

    maze_anim(game_maze);
    maze_print_maze(game_maze);

    // InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Maze game");
    // SetTargetFPS(30);
    // int enable_anim = 0, limit = 0;
    // while (!WindowShouldClose()) {
    //     if (limit >= 200) {
    //         maze_anim(game_maze);
    //         limit = 0;
    //     }

    //     BeginDrawing();
    //         ClearBackground(BLACK);
    //         DrawMaze(game_maze);
    //     EndDrawing();
    //     limit++;
    // }

    // free_maze(game_maze);
    // CloseWindow();
    return 0;
}
