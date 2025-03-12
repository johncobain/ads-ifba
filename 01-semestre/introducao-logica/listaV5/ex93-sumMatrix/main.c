/*Faça um programa em C para ler valores e armazená-los em uma matriz D 5 x 5. A seguir
o programa deverá calcular a soma dos valores que compõem a diagonal principal e a
diagonal secundária da matriz. 
*/
#include <stdio.h>
#define DIM 5

int main(){
    int matriz[DIM][DIM], diagPrin=0, diagSec=0, sum=0;
    int i, j;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            matriz[i][j] = (i*DIM)+j+1;
        }
    }
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(i==j)diagPrin += matriz[i][j];
            if(i+j==DIM-1) diagSec += matriz[i][j];
        }
    }
    sum = diagPrin+diagSec;
    if(DIM%2==1)sum-=matriz[DIM/2][DIM/2];

    for(i=0; i<DIM; i++){
        printf("\n[");
        for(j=0; j<DIM; j++){
            printf(" %02d ", matriz[i][j]);
        }
        printf("]\n");
    }
    printf("Soma da diagonal principal: %d\nSoma da diagonal secundaria: %d\nSoma de todos os valores das duas diagonais: %d",diagPrin,diagSec,sum);

    return 0;
}