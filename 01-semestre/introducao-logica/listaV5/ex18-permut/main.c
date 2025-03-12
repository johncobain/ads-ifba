//18. Escreva um programa que permute o valor de duas variáveis inteiras.(sem usar auxiliares)
#include <stdio.h>

int main(){
    int a, b;
    printf("Insira o valor da variavel a: ");
    scanf("%d", &a);
    printf("Insira o valor da variavel b: ");
    scanf("%d", &b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("a:%d - b:%d",a,b);

    return 0;
}