#include <stdio.h>

int main(){
    int posicoes[3], comprimento[3];
    int i, j, aux, area, compFechado=0;
    for(i=0;i<3;i++){
        scanf("%d %d", &posicoes[i], &comprimento[i]);
    }
    for(i=0;i<2;i++){
        for(j=i+1;j<3;j++){
            if(posicoes[i]>posicoes[j]){
                aux = posicoes[j];
                posicoes[j] = posicoes[i];
                posicoes[i] = aux;
                aux = comprimento[j];
                comprimento[j] = comprimento[i];
                comprimento[i] = aux;
            }
        }
    }
    if(posicoes[1]<(posicoes[0]+comprimento[0])){
        comprimento[1] = comprimento[1]-(comprimento[0]-posicoes[1]);
        posicoes[1]=(posicoes[0]+comprimento[0]);
    }
    if(posicoes[2]<(posicoes[1]+comprimento[1])){
        comprimento[2] = comprimento[2]-(comprimento[1]-posicoes[2]);
        posicoes[2]=(posicoes[1]+comprimento[1]);
    }
    for(i=0;i<3;i++){
        compFechado+=comprimento[i];
    }
    area = (600-compFechado)*100;
    printf("Area aberta: %dcm2", area);
    return 0;
}