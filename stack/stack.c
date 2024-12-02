#include "stack.h"

typedef int stack_key;
typedef struct nd_stack {
    stack_key value;
    struct nd_stack *next;
} Node_stack;

struct Stack {
    Node_stack *top;
    int length;
};

static void alloc_error( ){
    printf("Memoria insuficiente\n");
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
    Node_stack* node = (Node_stack *) malloc(sizeof(Node_stack));
    if (node == NULL) alloc_error();

    node->value = value;
    node->next = stack->top;

    stack->top = node;
    stack->length++;
    return true;
}

bool stack_pop(Stack *stack, stack_key *value) {
    if (stack_is_empty(stack)) return false;

    Node_stack *stack_top = stack->top;
    *value = stack_top->value;

    stack->top = stack_top->next;
    stack->length--;

    free(stack_top);
    return true;
}

bool stack_is_empty(Stack *stack) {
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

void stack_print(Stack *stack) {
    Node_stack *actual_node = stack->top;
    while (actual_node != NULL) {
        if (actual_node->value != '\0') {
            printf("%d", actual_node->value);
        }

        actual_node = actual_node->next;
    }
    printf("\n");
}
