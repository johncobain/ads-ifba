#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *p);

int main(){
    int var = 15;
    int *ptr;

    ptr = &var;
    display(var, ptr);

    update(&var);
    display(var, ptr);
    update(ptr);
    display(var, ptr);


    printf("\n\nEnd.\n");

    return 0;
}

void display(int var, int *ptr){
    printf("\n\n");

    printf ("conteudo de var           = %d\n", var);
    printf ("endereco de var           = %p\n", &var);
    printf ("conteudo apontado por ptr = %d\n", *ptr);
    printf ("endereco apontado ptr     = %p\n", ptr);
    printf ("endereco do ptr           = %p\n", &ptr);
}


void update(int *p){
    *p = *p+1;
}