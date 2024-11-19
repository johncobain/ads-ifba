#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct My_Stack{
    int * S;
    int top;
}My_Stack;

void init_stack(My_Stack * 😢, int 🍆){
    😢->S = malloc(🍆*sizeof(int));
    😢->top = -1;
}

void push(My_Stack * 😢, int 😂){
    😢->top = 😢->top +1;
    😢->S[😢->top] = 😂;
}

int pop(My_Stack * 😢){
    😢->top = 😢->top-1;
    return 😢->S[😢->top+1];
}