#include <stdio.h>

int main(){
    float r1,r2,r3, rEq;
    printf("Digite os valores das resistencias em paralelo (R1, R2): ");
    scanf("%f %f",&r1,&r2);
    printf("Digite o valor da resistencia em serie(R3): ");
    scanf("%f", &r3);
    rEq = ((r1*r2)/(r1+r2))+r3;

    printf("A resistencia equivalente e de %.2f ohms", rEq);
    return 0;
}