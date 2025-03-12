/*Escrever um algoritmo e implementá-lo em linguagem C que leia duas matrizes de
valores inteiros 3 por 4 e crie uma terceira matriz, que seja a soma das duas primeiras, e
uma quarta, que seja a diferença entre a primeira e a segunda. Mostrar as matrizes lidas e
calculadas*/
#include <stdio.h>
#define LINES 3
#define COLUMNS 4

int main(){
    int mat1[LINES][COLUMNS], mat2[LINES][COLUMNS], sum[LINES][COLUMNS], dif[LINES][COLUMNS];
    int i, j;
    
     for(i=0; i<LINES; i++){
        for(j=0; j<COLUMNS; j++){
            mat1[i][j] = (i*LINES)+j+1;
            mat2[i][j] = (i*LINES)+j+1;
        }
    }
     for(i=0; i<LINES; i++){
        for(j=0; j<COLUMNS; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
            dif[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    for(i=0; i<LINES; i++){
        printf("[");
        for(j=0; j<COLUMNS; j++){
            printf("  %02d  ",mat1[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    for(i=0; i<LINES; i++){
        printf("[");
        for(j=0; j<COLUMNS; j++){
            printf("  %02d  ",mat2[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    for(i=0; i<LINES; i++){
        printf("[");
        for(j=0; j<COLUMNS; j++){
            printf("  %02d  ",sum[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    for(i=0; i<LINES; i++){
        printf("[");
        for(j=0; j<COLUMNS; j++){
            printf("  %02d  ",dif[i][j]);
        }
        printf("]\n");
    }

    return 0;
}