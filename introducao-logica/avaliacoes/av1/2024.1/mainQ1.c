#include <stdio.h>

int main(){
    int dist, posicao;
    printf("Insira a distancia em quilometros percorrida pela particula:\\> ");
    scanf("%d", &dist);
    posicao = dist-3;
    posicao = posicao%8;
    switch (posicao){
    case 3:printf("atingiu o sensor 1");break;
    case 4:printf("atingiu o sensor 2");break;
    case 5:printf("atingiu o sensor 3");break;
    default:printf("nao atingiu nenhum sensor");
    }
    return 0;
}