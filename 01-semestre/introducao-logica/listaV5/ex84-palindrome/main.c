/*Escreva um programa em C que verifique se uma string normalizada é palíndrome (os
mesmos caracteres quando lida da direita para a esquerda)*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char str[MAX_STR], strN[MAX_STR], strReversed[MAX_STR];
    int i, j;
    int palindromo=1;
    printf("Insira um texto:\\> ");
    fgets(str, MAX_STR, stdin);
    j=0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]!=' '&&str[i]!='\n'){
            strN[j]= str[i];
            j++;
        }
        if(str[i]=='\n')str[i]='\0';
    }
    strN[j]= '\0';

    for(i=0; strN[i]!='\0'&&j>=0;i++){
        j--;
        strReversed[i]=strN[j];
    }
    strReversed[i]='\0';
    
    for(i=0; strN[i]!='\0'&&palindromo==1;i++){
        if(strN[i]!=strReversed[i]) palindromo=0;
    }

    printf("A palavra [%s] ao contrario eh [%s]\n", strN, strReversed);
    if(palindromo)
        printf("[%s] eh um palindromo", str);
    else
        printf("[%s] eh um palindromo", str);

    return 0;
}