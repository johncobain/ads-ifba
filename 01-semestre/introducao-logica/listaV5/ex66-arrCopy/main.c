/*. Faça um programa em C que copie o conteúdo de um vetor de 10 posições de inteiro em
um segundo vetor e imprima este último.*/
#include <stdio.h>

int main(){
    int arr[10], arrCopy[10], i;
    for (i = 0; i < 10; i++){
        printf("Insira o %do. elemento:\\> ", i);
        scanf("%d",&arr[i]);
    }
    for(i=0; i<10; i++){
        arrCopy[i] = arr[i];
        printf("Vetor copia na posicao %d: %d\n", i, arrCopy[i]);
    }
    return 0;
}