/*Escreva um programa em C, que gere a substring de uma string original, dado a posição
inicial e a final da substring*/
#include <stdio.h>

int main(){
    char str[50], subStr[50];
    int start, end;
    printf("Insira a string:\\> ");
    fgets(str,50,stdin);
    printf("Insira a posicao inicial e final da substring:\\> ");
    scanf("%d %d", &start, &end);
    for(int i = 0; start+i<=end+1; i++){
        if(start+i==end+1){
            subStr[i] = '\0';
        }else{
            subStr[i] = str[start+i];
        }
    }
    for(int i = 0; subStr[i]!='\0'; i++){
        printf("%c", subStr[i]);
    }
    return 0;
}