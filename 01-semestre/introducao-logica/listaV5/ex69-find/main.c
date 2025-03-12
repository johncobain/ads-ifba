/*Escreva um programa que leia um vetor de 15 posições de inteiros. Em seguida, o
programa deve ler um valor inteiro e imprimir o número de vezes que este valor ocorre
no vetor.*/
#include <stdio.h>

int main(){
    int arr[15], i, num, count;
    for(i=0;i<15;i++){
        printf("Insira o %do. elemento:\\> ",i);
        scanf("%d", &arr[i]);
    }
    printf("Insira um numero para verificar quanta vezes ele se repete no array:\\> ");
    scanf("%d", &num);
    count = 0;
    for(i = 0; i<15; i++){
        if(arr[i]==num){
            count++;
        }
    }
    printf("O numero %d aparece %d vezes no array.", num, count);
    return 0;
}