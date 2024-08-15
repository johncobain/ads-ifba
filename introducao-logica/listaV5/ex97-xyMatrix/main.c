/*. Escrever um algoritmo e implementá-lo em linguagem C que leia uma matriz de valores
inteiros 5 por 5 e a exiba. A seguir, leia dois números x e y e em seguida troque a xésima linha pela y-ésima linha, a x-ésima coluna com a y-ésima coluna, a diagonal
principal com a secundária e, por fim mostre a matriz assim modificada.*/
#include <stdio.h>
#define DIM 5

int main(){
    int matriz[DIM][DIM], aux[DIM], diagSec[DIM];
    int i, j, x, y;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            matriz[i][j] = (i*DIM)+j+1;
        }
    }

    printf("Insira um valor para x e um para y:\\> ");
    scanf("%d %d", &x, &y);
    x--; y--;

    for(i=0; i<DIM; i++){
        printf("[");
        for(j=0; j<DIM; j++){
            printf("  %02d  ",matriz[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    for(i=0; i<DIM; i++){
        aux[i] = matriz[x][i];
        matriz[x][i] = matriz[y][i];
        matriz[y][i] = aux[i];
    }
    for(i=0; i<DIM; i++){
        aux[i] = matriz[i][x];
        matriz[i][x] = matriz[i][y];
        matriz[i][y] = aux[i];
    }
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(i==j){
                aux[i] = matriz[i][j];
            }
            if(i+j==DIM-1){
                diagSec[i]=matriz[i][j];
            }
        }
    }

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(i==j){
                matriz[i][j]=diagSec[i];
            }
            if(i+j==DIM-1){
                matriz[i][j]=aux[i];
            }
        }
    }

    for(i=0; i<DIM; i++){
        printf("[");
        for(j=0; j<DIM; j++){
            printf("  %02d  ",matriz[i][j]);
        }
        printf("]\n");
    }
    return 0;
}