/*. Escrever um algoritmo e implementá-lo em linguagem C que linearize uma matriz de 6
por 6, colocando os valores contidos nela em um vetor de 36 elementos e mostrar o
conteúdo do vetor.*/
#include <stdio.h>
#define DIM 6

int main(){
    int matriz[DIM][DIM], linear[DIM*DIM];
    int i, j;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            matriz[i][j] = (i*DIM)+j+1;
        }
    }
    printf("Valor a ser multiplicado: ");
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            linear[(i*DIM)+j]=matriz[i][j];
        }
    }

    for(i=0; i<DIM; i++){
        printf("\n[");
        for(j=0; j<DIM; j++){
            printf(" %02d ", matriz[i][j]);
        }
        printf("]\n");
    }
    printf("\n[");
    for(i=0; i<DIM*DIM; i++){
        printf(" %d ",linear[i]);
    }
    printf("]\n");

    return 0;
}