#include <stdio.h>

int main(){
    char lido;
    while((lido = getchar()) != 'S'){
        printf("To dentro\n");
    }
    printf("to fora");
    return 0;
}