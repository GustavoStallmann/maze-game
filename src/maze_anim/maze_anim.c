#include "./maze_anim.h"
#include "../utils/utils.h"
#include <raylib.h>

static bool is_movement_valid(Vector2 actual_block, Vector2 next_block) {
    int actualX = (int)actual_block.x, actualY = (int)actual_block.y;
    int nextX = (int)next_block.x, nextY = (int)next_block.y;

    // Valid on X axis
    if ((actualX + 1 == nextX || actualX - 1 == nextX) && actualY == nextY) {
        return true;
    }

    // Valid on Y axis
    if ((actualY + 1 == nextY || actualY - 1 == nextY) && actualX == nextX) {
        return true;
    }

    // Valid if the same
    if (actualX == nextX && actualY == nextY) {
        return true;
    }

    return false;
}

int maze_anim(Maze *maze, Stack *maze_movements) {
    Vector2 initial_block = maze_get_block(maze, INITIAL_BLOCK);
    if (initial_block.x >= 0 && initial_block.y >= 0) {
        maze_set_block_type(maze, initial_block, ACTUAL_BLOCK);
    }

    Vector2 next_step = maze_get_next_solution_step(maze);
    if (next_step.x < 0 || next_step.y < 0) return 1;

    Vector2 actual_block = maze_get_block(maze, ACTUAL_BLOCK);

    if (is_movement_valid(actual_block, next_step)) {
        maze_remove_next_solution_step(maze);
        maze_set_actual_block(maze, next_step);
        stack_push(maze_movements, next_step);
    } else {
        Vector2 backtrack_block;
        if (stack_pop(maze_movements, &backtrack_block)) {
            maze_set_actual_block(maze, backtrack_block);
        }
    }

    return 0;
}
