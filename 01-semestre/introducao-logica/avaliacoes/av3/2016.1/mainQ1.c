#include <stdio.h>
#define TAM 3

int main(){
    int quadrado[TAM][TAM], somaPLinha=0, soma, ehMagico=1;
    int i, j;

    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &quadrado[i][j]);
        }
    }
    for(i=0; i<TAM; i++)somaPLinha+=quadrado[0][i];

    for(i=0; i<TAM&& ehMagico==1; i++){soma=0;
        for(j=0; j<TAM; j++)soma+= quadrado[i][j];
        if(soma!=somaPLinha)ehMagico=0;

    }
    for(i=0; i<TAM&& ehMagico==1; i++){soma=0;
        for(j=0; j<TAM; j++)soma+= quadrado[j][i];
        if(soma!=somaPLinha)ehMagico=0;

    }
    soma=0;
    for(i=0; i<TAM&& ehMagico==1; i++){
        soma+= quadrado[i][i];
    }
    if(soma!=somaPLinha)ehMagico=0;

    if(ehMagico)printf("Saida: %d",somaPLinha);
    else printf("Saida: 0");

    return 0;
}