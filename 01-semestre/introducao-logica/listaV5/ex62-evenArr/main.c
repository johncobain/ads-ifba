/*Faça um programa em C que leia um array de 10 posições e conte quantos números pares
são elementos do array. Imprima esta quantidade.*/
#include <stdio.h>

int main(){
    int arr[10], evenN = 0;
    for(int i = 0; i<10; i++){
        printf("Insira o valor da posicao %d do array:\\> ", i);
        scanf("%d", &arr[i]);
        if(arr[i]%2==0) evenN+=1;
    }
    printf("O array tem %d numeros pares.", evenN);

    return 0;
}