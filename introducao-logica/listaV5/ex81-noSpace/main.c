/*. Escreva um programa em C que normalize uma string lida, em uma nova string.
Normalizar uma string é o processo de remover os espaços excedentes que separam as
palavras.*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char str[MAX_STR], strNormalized[MAX_STR];
    int i, j;
    printf("Insira um texto:\\> ");
    fgets(str, MAX_STR, stdin);
    j=0;
    for(i=0; str[i]!='\0'; i++){
        if((str[i]!=' ' || str[i+1]!=' ')&&str[i]!='\n'){
            strNormalized[j]= str[i];
            j++;
        }
    }
    strNormalized[j]= '\0';

    puts(strNormalized);

    return 0;
}