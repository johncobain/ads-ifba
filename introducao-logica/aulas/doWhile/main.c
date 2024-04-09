#include <stdio.h>

int main(){
    char lido;
    do{
        scanf("%c", &lido);
        printf(".");
    }while (lido!='S');
    return 0;
}