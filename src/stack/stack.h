#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"

// Forward declaration of the Stack structure
typedef struct Stack Stack;

// Type definition for the stack elements
typedef Vector2 stack_key;

/**
 * @brief Creates a new stack.
 *
 * @return Pointer to the newly created stack.
 */
Stack* new_stack();

/**
 * @brief Pushes a value onto the stack.
 *
 * @param stack Pointer to the stack.
 * @param value The value to push onto the stack.
 * @return true if the operation is successful, false otherwise.
 */
bool stack_push(Stack *stack, stack_key value);

/**
 * @brief Pops a value from the stack.
 *
 * @param stack Pointer to the stack.
 * @param value Pointer to the variable where the popped value will be stored.
 * @return true if the operation is successful, false otherwise.
 */
bool stack_pop(Stack *stack, stack_key *value);

/**
 * @brief Returns the value at the top of the stack without removing it.
 *
 * @param stack Pointer to the stack.
 * @return stack_key The value at the top of the stack.
 */
stack_key stack_peek(Stack *stack);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack Pointer to the stack.
 * @return true if the stack is empty, false otherwise.
 */
bool stack_is_empty(Stack *stack);

/**
 * @brief Frees the memory allocated for the stack.
 *
 * @param stack Pointer to the stack to be freed.
 */
void stack_free(Stack *stack);

/**
 * @brief Clear stack removing all nodes
 *
 * @param stack Pointer to the stack to be freed.
 */
bool stack_clear(Stack *stack);

/**
 * @brief Prints the contents of the stack.
 *
 * @param stack Pointer to the stack to be printed.
 */
void stack_print(Stack *stack);

/**
 * @brief return the stack length (amount of nodes)
 *
 * @param stack Pointer to the stack to be printed.
 */
int stack_get_length(Stack *stack);

#endif
