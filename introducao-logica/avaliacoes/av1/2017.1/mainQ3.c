#include <stdio.h>

int main(){
    float P1, P2, C1, C2, T1, T2;
    printf("Insira o peso da crianca do lado esquerdo e da crianca do lado direito da gangorra: ");
    scanf("%f %f", &P1, &P2);
    printf("Insira o comprimento do lado esquerdo e do lado direito da gangorra: ");
    scanf("%f %f", &C1, &C2);
    T1 = P1*C1; T2 = P2*C2;
    if(T1>T2){printf("A gangorra pendera para o lado 1(esquerdo)");}
    else if(T2>T1){printf("A gangorra pendera para o lado 2(direito)");}
    else{printf("A gangorra ficara equilibrada");}
    return 0;
}