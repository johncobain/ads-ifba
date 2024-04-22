/*. Escreva um programa em C, que leia uma string e conte quantas ocorrências de vogais
existem nesta string.*/
#include <stdio.h>

int main(){
    char str[50];
    int vogal=0, i;
    fgets(str, 50, stdin);

    for(i=0;str[i]!='\0';i++){
        switch (str[i]){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vogal++;
        }
    }
    printf("Quantidade de vogais: %d", vogal);

    return 0;
}