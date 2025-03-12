/*Elabore um programa em C que leia valores inteiros para preencher uma matriz A 5 x 5.
Você deverá criar adicionalmente dois vetores de 5 elementos: somaLinhas e
somaColunas. Em cada posição do vetor somaLinhas deverá ser armazenada a soma da
linha correspondente na matriz A. Da mesma forma, em cada posição do vetor
somaColunas deverá ser armazenada a soma da coluna correspondente na matriz A.*/
#include <stdio.h>
#define DIM 5

int main(){
    int matriz[DIM][DIM], somaLinhas[DIM], somaColunas[DIM];
    int i, j;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            matriz[i][j] = (i*DIM)+j+1;
        }
        somaLinhas[i]=0;
        somaColunas[i]=0;
    }
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            somaLinhas[i] += matriz[i][j];
            somaColunas[i] += matriz[j][i];
        }
    }

    for(i=0; i<DIM; i++){
        printf("[");
        for(j=0; j<DIM; j++){
            printf("  %02d  ",matriz[i][j]);
        }
        printf("]\n");
    }

    printf("\nSoma das linhas:\n");
    for(i=0; i<DIM;i++){
        printf("\tLinha %d: %d\n",i+1, somaLinhas[i]);
    }

    printf("\nSoma das colunas:\n");
    for(i=0; i<DIM;i++){
        printf("\tColuna %d: %d\n",i+1, somaColunas[i]);
    }

    return 0;
}