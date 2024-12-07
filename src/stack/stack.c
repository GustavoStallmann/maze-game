#include "stack.h"
#include <raylib.h>
#include <time.h>

typedef struct nd_stack {
    stack_key value;
    struct nd_stack *next;
} Node_stack;

struct Stack {
    Node_stack *top;
    int length;
};

static void alloc_error( ) {
    printf("Erro stack TAD: memoria insuficiente\n");
    exit(1);
}

Stack* new_stack( ) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) alloc_error();

    stack->top = NULL;
    stack->length = 0;
    return stack;
}

bool stack_push(Stack *stack, stack_key value) {
    if (stack == NULL) return false;

    Node_stack* node = (Node_stack *) malloc(sizeof(Node_stack));
    if (node == NULL) alloc_error();

    node->value = value;
    node->next = stack->top;

    stack->top = node;
    stack->length++;
    return true;
}

bool stack_pop(Stack *stack, stack_key *value) {
    if (stack == NULL) return false;
    if (stack_is_empty(stack)) return false;

    Node_stack *stack_top = stack->top;
    *value = stack_top->value;

    stack->top = stack_top->next;
    stack->length--;

    free(stack_top);
    return true;
}

bool stack_is_empty(Stack *stack) {
    if (stack == NULL) return false;

    return stack->length == 0;
}

void stack_free(Stack *stack) {
    if (stack == NULL) return;

    while (stack->top != NULL) {
        Node_stack *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    free(stack);
}

bool stack_clear(Stack *stack) {
    if (stack == NULL) return false;

    while (!stack_is_empty(stack)) {
        stack_key temp;
        stack_pop(stack, &temp);
    }

    return true;
}
void stack_print(Stack *stack) {
    if (stack == NULL) return;
    Node_stack *actual_node = stack->top;
    while (actual_node != NULL) {
        printf("(%d | %d)\n", (int) actual_node->value.x, (int) actual_node->value.y);
        actual_node = actual_node->next;
    }
    printf("\n");
}

int stack_get_length(Stack *stack) {
    if (stack == NULL) return -1;

    return stack->length;
}
