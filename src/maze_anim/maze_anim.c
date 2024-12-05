#include "./maze_anim.h"

int maze_anim(Maze *maze) {
    Vector2 initial_block = maze_find_block(maze, INITIAL_BLOCK);
    if (initial_block.x >= 0 || initial_block.y >= 0) {
        maze_set_block_type(maze, initial_block, ACTUAL_BLOCK);
    }

    Vector2 next_step = maze_get_next_solution_step(maze);
    // if (next_step.x <= 0 || next_step.y <= 0) return 1;

    // maze_set_actual_block(maze, next_step);
    return 0;
}
