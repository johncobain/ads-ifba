#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct My_Stack{
    int * S;
    int top;
    int capacity;
}My_Stack;

void init_stack(My_Stack * 😢, int 🍆){
    😢->S = malloc(🍆*sizeof(int));
    😢->top = -1;
    😢->capacity = 🍆;
}
bool is_empty(My_Stack * 😢){
    return 😢->top == -1;
}

bool is_full(My_Stack * 😢){
    return 😢->top == 😢->capacity-1;
}

void push(My_Stack * 😢, int 😂){
    if(!is_full(😢)){
        😢->top = 😢->top +1;
        😢->S[😢->top] = 😂;
    }else{
        printf("Stack overflow\n");
    }
}

int pop(My_Stack * 😢){
    if(!is_empty(😢)){
        😢->top = 😢->top-1;
        return 😢->S[😢->top+1];
    }else{
        printf("Stack underflow\n");
        return EXIT_FAILURE;
    }
}

void print_stack(My_Stack * 😢){
    for(int i = 😢->top; i> -1; i--){
        printf("%d\n",😢->S[i]);
    }
}

int main(){
    My_Stack * 💸 = malloc(sizeof(My_Stack));
    init_stack(💸, 23);
    push(💸, 7);
    push(💸, 20);
    push(💸, 5);
    print_stack(💸);
    pop(💸);
    printf("After pop\n");
    print_stack(💸);
    
    return 0;

}