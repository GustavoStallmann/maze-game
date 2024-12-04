#include "maze_solver.h"

struct Solver {
    Vector2 *solution_path;
    uint solution_blocks;
};

Solver* new_solver( ) {
    Solver* maze_solve = (Solver *) malloc(sizeof(Solver));
    if (maze_solve == NULL) alloc_error();

    maze_solve->solution_path = NULL;
    maze_solve->solution_blocks = 0;

    return maze_solve;
}

static Vector2 is_movement_valid(Maze *maze, Vector2 pos, Moves move_type) {
    if (maze == NULL) return (Vector2){-1, -1}; // Check for null maze pointer

    int x = (int) pos.x;
    int y = (int) pos.y;

    Vector2 movement_position;
    switch (move_type) {
        case UP:
            movement_position = (Vector2){x, y-1};
            break;
        case RIGHT:
            movement_position = (Vector2){x+1, y};
            break;
        case DOWN:
            movement_position = (Vector2){x, y+1};
            break;
        case LEFT:
            movement_position = (Vector2){x-1, y};
            break;
        default: //invalid movement
            return (Vector2){-1, -1};
    }

    int maze_size = get_maze_size(maze);
    if (movement_position.x < 0 || movement_position.y < 0 ||
        movement_position.x >= maze_size || movement_position.y >= maze_size) {
        return (Vector2){-1, -1}; // Out-bound movement
    }

    int block_type = maze_get_block_type(maze, movement_position);
    if (block_type == WALL_BLOCK) return (Vector2){-1, -1}; // Cannot walk over wall block

    return movement_position;
}

static int solver_invert_solution_path(Solver *solver) {

}

int solver_set_solution_path(Solver *solver) {

}

Solver* Solver_sove(Maze *maze) {
    Solver *maze_solve = new_solver();
    int free_block_amount = maze_get_block_amount(maze, FREE_BLOCK);
    if (free_block_amount <= 0) return NULL;

    Vector2 *blocks_order = (Vector2 *) calloc(free_block_amount, sizeof(Vector2));
    int visited_count = 0;

    Vector2 initial_position = maze_find_position(maze, INITIAL_BLOCK);
    Stack *available_pos = new_stack();
    stack_push(available_pos, initial_position);

    while (!stack_is_empty(available_pos)) {
        Vector2 current_pos;
        int popped = stack_pop(available_pos, &current_pos);
        if (!popped) break;

        blocks_order[visited_count++] = current_pos;

        if (maze_get_block_type(maze, current_pos) == TARGET_BLOCK) {
            break; // Stop if the final block is found
        }

        Vector2 moves[] = {
            is_movement_valid(maze, current_pos, UP),
            is_movement_valid(maze, current_pos, RIGHT),
            is_movement_valid(maze, current_pos, DOWN),
            is_movement_valid(maze, current_pos, LEFT)
        };

        for (int i = 3; i >= 0; i--) { // Push moves in reverse order for DFS
            int already_visited = 0;
            for (int j = 0; j < visited_count; j++) {
                if (blocks_order[j].x == moves[i].x && blocks_order[j].y == moves[i].y) {
                    already_visited = 1;
                    break;
                }
            }

            if (moves[i].x != -1 && moves[i].y != -1 && !already_visited) {
                stack_push(available_pos, moves[i]);
            }
        }
    }

    return maze_solve;
}
