#include <stdio.h>

int main(){
    int num, d3,d2,d1,d0,DV,numD;
    printf("Insira um numero entre 0 e 999:\\> ");
    scanf("%d", &num);
    d0 = num%7;
    d1 = (num/7)%7;
    d2 = ((num/7)/7)%7;
    d3 = (((num/7)/7)/7)%7;
    DV = (d0+d1+d2+d3)%7;
    numD = num*10 + DV;
    printf("O numero com o Digito Verificador eh %d", numD);
    return 0;
}