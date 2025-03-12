/*. Faça um programa em C que leia um array de 20 inteiros e imprima o menor e o maior
valor dentre os elementos do array.*/
#include <stdio.h>

int main(){
    int arr[20], menor, maior, i;
    for(i=0; i<20; i++){
        printf("Insira o %do. elemento:\\> ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0; i<20; i++){
        if(i==0){
            menor = arr[i];
            maior = arr[i];
        }
        if(arr[i]<menor){
            menor = arr[i];
        }
        if(arr[i]>maior){
            maior = arr[i];
        }
    }
    printf("Menor: %d\nMaior: %d",menor, maior);
    return 0;
}