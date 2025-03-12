#include <stdio.h>
#define TAM 10

int main(){
    int matriz[TAM][TAM], soma, ehPermut=1;
    int i,j;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            printf("Linha %d coluna %d: ",i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0; i<TAM&&ehPermut==1; i++){
        soma=0;
        for(j=0; j<TAM; j++)soma+=matriz[i][j];
        if(soma!=1)ehPermut=0;
    }
    for(j=0; j<TAM&&ehPermut==1; j++){
        soma=0;
        for(i=0; i<TAM; i++)soma+=matriz[i][j];
        if(soma!=1)ehPermut=0;
    }
    printf("\nMatriz:\n");
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    if(ehPermut==1)printf("A matriz eh uma matriz de permutacao");
    else printf("A matriz NAO eh uma matriz de permutacao");

    return 0;
}