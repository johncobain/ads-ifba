/*Escreva um programa que leia o índice pluviométrico de cada dia do mês de junho e
informe o dia que mais choveu, o dia que menos choveu e as médias pluviométricas de
cada uma das duas quinzenas.*/
#include <stdio.h>

int main(){
    int indices[30], maiorI, maiorDia, menorI, menorDia, sum1Q=0, sum2Q=0;
    float media1Q, media2Q;
    //coletar indices
    for(int i = 0; i<30; i++){
        printf("Insira o indice pluviometrico do dia %d de junho:\\> ",i+1);
        scanf("%d", &indices[i]);
    }
    //analisar maior e menor indice
    for(int i = 0; i<30; i++){
        if(i == 0){
            maiorI= indices[i];
            maiorDia = i+1;
            menorI = indices[i];
            menorDia = i;
        }
        if(indices[i]>maiorI){
            maiorI= indices[i];
            maiorDia = i+1;
        }
        if(indices[i]<menorI){
            menorI = indices[i];
            menorDia = i+1;
        }
    }
    //media por quinzena
    for(int  i = 0; i<30; i++){
        if(i<15){
            sum1Q+=indices[i];
        }else{
            sum2Q+=indices[i];
        }
    }
    media1Q = sum1Q/15.0;
    media2Q = sum2Q/15.0;

    printf("\nDia com maior indice pluviometrico: %d (%dmm)\n", maiorDia, maiorI);
    printf("Dia com menor indice pluviometrico: %d (%dmm)\n", menorDia, menorI);
    printf("\nMedia do indice pluviometrico na primeira quinzena: %.2fmm\n", media1Q);
    printf("Media do indice pluviometrico na segunda quinzena: %.2fmm\n", media2Q);
}