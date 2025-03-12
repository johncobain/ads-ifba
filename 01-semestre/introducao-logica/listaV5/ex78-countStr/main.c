/*Escreva um programa em C, que leia uma string e um caracter e conte o número de
ocorrências do caracter lido na string.*/
#include <stdio.h>

int main(){
    char str[50], ch;
    int count=0;
    printf("Insira um texto:\\> ");
    fgets(str, 50, stdin);
    printf("Insira um caracter para ser contado:\\> ");
    scanf("%c", &ch);
    for(int i = 0; str[i]!='\0'; i++){
        if(str[i]==ch)count++;
    }
    printf("O caracter (%c) aparece %d no texto!", ch, count);
    return 0;
}