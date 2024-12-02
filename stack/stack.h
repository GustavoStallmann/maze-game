#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Forward declaration of the Stack structure
typedef struct Stack Stack;

// Type definition for the stack elements
typedef int stack_key;

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
 * @brief Prints the contents of the stack.
 *
 * @param stack Pointer to the stack to be printed.
 */
void stack_print(Stack *stack);

#endif
