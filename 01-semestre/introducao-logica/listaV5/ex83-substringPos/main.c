/*Escreva um programa em C, que gere a substring de uma string original, dado a posição
inicial e a final da substring*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char str[MAX_STR], subStr[MAX_STR];
    int posI, posF, i, j=0;
    printf("Insira um texto:\\> ");
    fgets(str, MAX_STR, stdin);
    printf("Insira a posicao inicial e final da substring:\\> ");
    scanf("%d %d", &posI, &posF);
    for(i=posI; i<=posF && str[i]!='\0'; i++, j++){
        if(str[i]!='\n')
            subStr[j]=str[i];
    }
    subStr[j]='\0';

    puts(subStr);

    return 0;
}