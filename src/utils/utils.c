#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void alloc_error( ) {
    printf("Erro: memoria insuficiente");
    exit(1);
}

void print_vec2(Vector2 vec) {
    printf("[%.2f|%.2f]\n", vec.x, vec.y);
}
