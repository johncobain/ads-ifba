/*Escrever um algoritmo e implementá-lo em linguagem C que leia uma matriz de valores
inteiros 6 por 6 e um valor inteiro qualquer, posteriormente multiplicar a matriz pelo
valor lido e colocar o resultado na própria matriz. */
#include <stdio.h>
#define DIM 6

int main(){
    int matriz[DIM][DIM];
    int i, j, prod;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Valor a ser multiplicado: ");
    scanf("%d", &prod);
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            matriz[i][j]*=prod;
        }
    }

    for(i=0; i<DIM; i++){
        printf("\n[");
        for(j=0; j<DIM; j++){
            printf(" %02d ", matriz[i][j]);
        }
        printf("]\n");
    }

    return 0;
}