/*Escreva um programa que ordene um array de inteiros de 15 posições utilizando o
método da bolha (bubble sort).*/
#include <stdio.h>
#define QNT_N 15

int main(){
    int arr[QNT_N], aux;
    for(int i = 0; i<QNT_N; i++){
        printf("Insira o %02do. elemento:\\> ", i);
        scanf("%d", &arr[i]);
    }

    for(int leap = 0; leap<QNT_N-1; leap++){
        for(int i = 0; i<QNT_N-1; i++){
            if(arr[i]>arr[i+1]){
                aux = arr[i+1];
                arr[i+1] =arr[i];
                arr[i] = aux;
            }
        }

    }
    printf("\n");
    for(int i=0; i<QNT_N; i++){
        printf("Pos. %02d: %d\n", i, arr[i]);
    }
    return 0;
}