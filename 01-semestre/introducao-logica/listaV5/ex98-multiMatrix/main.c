/*Escrever um algoritmo e implementá-lo em linguagem C que leia duas matrizes (4x3 e
3x2), calcule e imprima a matriz que representa o produto entre as duas matrizes lidas.*/
#include <stdio.h>

int main(){
    int matriz1[4][3], matriz2[3][2], matrizP[4][2];
    int i, j, k, prod;

    for(i=0; i<4; i++){
        for(j=0; j<3; j++){
            matriz1[i][j] = (i*3)+j+1;
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            matriz2[i][j] = (i*2)+j+1;
        }
    }
    for(i=0; i<4; i++){
        for(j=0; j<2; j++){
            matrizP[i][j] = 0;
        }
    }
    for(i=0; i<4; i++){
        for(j=0; j<2; j++){
            prod=0;
            for(k=0;k<3;k++){
                prod+=matriz1[i][k]*matriz2[k][j];
            }
                matrizP[i][j]=prod;
        }
    }
    for(i=0; i<4; i++){
        printf("[");
        for(j=0; j<3; j++){
            printf("  %02d  ",matriz1[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    for(i=0; i<3; i++){
        printf("[");
        for(j=0; j<2; j++){
            printf("  %02d  ",matriz2[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");

    for(i=0; i<4; i++){
        printf("[");
        for(j=0; j<2; j++){
            printf("  %02d  ",matrizP[i][j]);
        }
        printf("]\n");
    }
    printf("\n\n");
    return 0;
}