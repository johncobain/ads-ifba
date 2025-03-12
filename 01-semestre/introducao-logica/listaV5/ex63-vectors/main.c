/*Escreva um programa que leia dois vetores de números reais de mesma dimensão (10
posições), e imprima o vetor resultante da soma destes vetores*/
#include <stdio.h>

int main(){
    float v1[10], v2[10], vRes[10];
    int i, j;
    for(i = 0; i<10; i++){
        scanf("%f %f", &v1[i], &v2[i]);
    }
    for(j=0; j<10; j++){
        vRes[j] = v1[j]+ v2[j];

        printf("-%.2f-", vRes[j]);
    }

    return 0;
}