#include <stdio.h>

int main(){
    float V;
    int N, M;
    printf("Qual o valor da aposta? R$");
    scanf("%f", &V);
    printf("Qual serah o numero apostado? ");
    scanf("%d", &N);
    printf("Qual foi numero sorteado? ");
    scanf("%d", &M);
    if(N>99999) printf("Numero de aposta invalido.");
    else{
        if(N % 10000==M % 10000){
            V *= 3000;
        }else if(N %1000 == M %1000){
            V *=500;
        }else if(N %100 == M %100){
            V *=50;
        }else if(((N-1)%100)/4 == ((M-1)%100)/4){
            V *=16;
        }else V = 0;
        printf("Seu premio foi de R$%.2f", V);
    }

    return 0;
}