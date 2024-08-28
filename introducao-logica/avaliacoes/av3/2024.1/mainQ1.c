#include <stdio.h>
#define TAM 50

int main(){
    int folha[TAM][TAM], tamanho, linhaCorte=0, maiorCorte=0, somaCorte;
    int i, j;
    for(i=0; i<TAM; i++)for(j=0; j<TAM; j++)folha[i][j]=0;
    for(i=0; i<TAM; i++){
        scanf("%d",&tamanho);
        for(j=0; j<tamanho; j++){
            folha[j][i]=1;
        }
    }
    for(i=0; i<TAM; i++){
        somaCorte=0;
        if(i==0){
            for(j=0; j<TAM; j++){
                if(folha[0][j]==1){
                    somaCorte++;
                    while (folha[0][j]==1)j++;                    
                }
            }if(somaCorte>maiorCorte){maiorCorte=somaCorte; linhaCorte=i;}
        }else{
            for(j=0; j<TAM; j++){
                if(folha[0][j]==1){
                    somaCorte++;
                    while (folha[0][j]==1)j++;                    
                }
            }
            for(j=0; j<TAM; j++){
                if(folha[i][j]==1){
                    somaCorte++;
                    while (folha[i][j]==1)j++;                    
                }
            }if(somaCorte>maiorCorte){maiorCorte=somaCorte; linhaCorte=i;}
        }
    }
    printf("Altura %d - Cortes %d",linhaCorte,maiorCorte);
    return 0;
}