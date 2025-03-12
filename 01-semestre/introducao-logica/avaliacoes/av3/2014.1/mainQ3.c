#include <stdio.h>
#define TAM 100
#define MAX 256

int main(){
    char produtos[TAM][MAX];
    float precos[TAM], media, soma=0;
    int i, posicaoBarato=0;

    for(i=0;i<TAM;i++){
        printf("Produto: ");
        fgets(produtos[i],MAX,stdin);
        fflush(stdin);
        printf("Preco: ");
        scanf("%f", &precos[i]);
        fflush(stdin);
    }
    for(i=0;i<TAM;i++){
        soma+= precos[i];
    }
    media= soma/TAM;
    for(i=0;i<TAM;i++){
        if(precos[i]<media)precos[i]=precos[i]+(precos[i]*0.1);
    }
    for(i=0;i<TAM;i++){
        if(precos[i]<precos[posicaoBarato])posicaoBarato=i;
    }
    printf("R$%.2f - %s", precos[posicaoBarato], produtos[posicaoBarato]);

    return 0;
}