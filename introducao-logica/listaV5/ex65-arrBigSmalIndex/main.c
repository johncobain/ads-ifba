/*. Faça um programa em C que leia um array de 20 inteiros e imprima o menor e o maior
valor dentre os elementos do array, bem como suas respectivas posições.*/
#include <stdio.h>

int main(){
    int arr[20], menor, maior, indexMenor, indexMaior, i;
    for(i=0; i<20; i++){
        printf("Insira o %do. elemento:\\> ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0; i<20; i++){
        if(i==0){
            menor = arr[i];
            indexMenor = i;
            maior = arr[i];
            indexMaior = i;
        }
        if(arr[i]<menor){
            menor = arr[i];
            indexMenor = i;
        }
        if(arr[i]>maior){
            maior = arr[i];
            indexMaior = i;
        }
    }
    printf("Menor: %d Posicao: %d\nMaior: %d Posicao: %d",menor, indexMenor, maior, indexMaior);
    return 0;
}