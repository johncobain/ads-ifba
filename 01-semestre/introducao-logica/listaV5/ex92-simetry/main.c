/*. Elabore um programa em C, para ler valores e armazená-los em uma matriz 5 x 5. Após o
programa deverá responder se a matriz é ou não uma matriz simétrica. Uma matriz
simétrica possui a mesma composição de valores abaixo e acima da diagonal principal.*/
#include <stdio.h>
#define DIM 5

int main(){
    int matriz[DIM][DIM], fLinha[DIM], fColuna[DIM], lLinha[DIM], lColuna[DIM];
    int i, j, first=1, last=1;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(i==0)fLinha[j]=matriz[i][j];
            if(j==0)fColuna[i] = matriz[i][j];

            if(i==DIM-1)lLinha[j]=matriz[i][j];
            if(j==DIM-1)lColuna[i] = matriz[i][j];
        }
    }

    for(i=0; i<DIM; i++){
        printf("\n[");
        for(j=0; j<DIM; j++){
            printf(" %02d ", matriz[i][j]);
        }
        printf("]\n");
    }

    for(i=0; i<DIM&&first==1; i++){
        if(fLinha[i]!=fColuna[i]) first=0;
    }
    for(i=0; i<DIM&&last==1; i++){
        if(lLinha[i]!=lColuna[i]) last=0;
    }

    if(first&&last){
        printf("A matriz eh simetrica.");
    }else{
        printf("A matriz NAO eh simetrica.");
    }
    return 0;
}