#include <stdio.h>

int main(){
    // Escreva um programa que leia um número e exiba se ele é positivo ou negativo.
    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);

    if(num>=0){
        printf("%d eh um numero positivo.", num);
    }else{
        printf("%d eh um numero negativo.", num);
    }
    return 0;
}