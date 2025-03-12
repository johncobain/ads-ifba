//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int top;
    char names[512][512];
} Stack;

void pop(Stack *s);
void push(Stack *s, char name[]);
void initializeStack(Stack *s);

int main() {
    FILE *fp_in = fopen("L1Q2.in", "r");
    FILE *fp_out = fopen("L1Q2.out", "w");
    char line[1000];

    if (fp_in == NULL || fp_out == NULL) {
        printf("Arquivos não podem ser abertos.\n");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    int lineCount = 0;

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        char text[1000];
        int initialized = 0;
        int popCount = 0;

        line[strcspn(line, "\n")] = '\0'; // Remove o \n da linha lida
        line[strcspn(line, "\r")] = '\0'; // Remove o \r da linha lida

        Stack stack, secondary;
        initializeStack(&stack);
        initializeStack(&secondary);

        char *slice = strtok(line, space); // Quebra a linha em tokens

        while (slice != NULL) {
            if (stack.top == 0 || strcmp(slice, stack.names[stack.top - 1]) >= 0) {
                push(&stack, slice);
                if(initialized == 0){
                    if(lineCount == 0){
                        sprintf(text, "push-%s", slice);
                    }else{
                        sprintf(text, "\npush-%s", slice);
                    }
                    initialized = 1;
                }else{
                    sprintf(text, "%s push-%s", text, slice);
                }
            } else {
                popCount = 0;
                while (stack.top > 0 && strcmp(slice, stack.names[stack.top - 1]) < 0) {
                    push(&secondary, stack.names[stack.top - 1]);
                    pop(&stack);
                    popCount++;
                }
                sprintf(text, "%s %dx-pop", text, popCount);
                push(&stack, slice);
                sprintf(text, "%s push-%s", text, slice);
                while (secondary.top > 0) {
                    push(&stack, secondary.names[secondary.top - 1]);
                    sprintf(text, "%s push-%s", text, secondary.names[secondary.top - 1]);
                    pop(&secondary);
                }
            }
            slice = strtok(NULL, " ");
        }
        fputs(text, fp_out);
        lineCount++;
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

void initializeStack(Stack *s) {
    s->top = 0;
    memset(s->names, 0, sizeof(s->names));
}

void pop(Stack *s) {
    if (s->top > 0) {
        s->top--;
    }
}

void push(Stack *s, char name[]) {
    if (s->top < 512) { // Limite da pilha
        strcpy(s->names[s->top], name);
        s->top++;
    }
}
