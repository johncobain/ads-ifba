/*. Faça um programa em C que leia dois vetores de 10 posições de inteiros e copie o maior
valor dos dois em cada posição em um terceiro vetor. Em seguida, imprima este terceiro
vetor.*/
#include <stdio.h>

int main(){
    int arr1[10], arr2[10], arrBig[10], i;
    for(i = 0; i<10; i++){
        printf("Insira o elemento %d do primeiro vetor:\\> ", i);
        scanf("%d", &arr1[i]);
        printf("Insira o elemento %d do segundo vetor:\\> ", i);
        scanf("%d", &arr2[i]);
    }
    for(i = 0; i<10; i++){
        arrBig[i] = arr1[i]>arr2[i]? arr1[i]: arr2[i];

        printf("\nPosicao %d: %d\n",i,arrBig[i]);
    }

    return 0;
}