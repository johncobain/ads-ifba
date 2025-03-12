#include <stdio.h>

int main(){
    int num8, d2,d1,d0, num10;
    printf("Insira um numero de 3 digitos em octal(max 777): ");
    scanf("%d", &num8);
    if(num8>777){
        printf("numero invalido");
    }else{
        d2 = num8/100;
        d1 = (num8%100)/10;
        d0 = num8%10;
        num10 = (d2*(8*8))+(d1*8)+d0;
        printf("%d(8) = %d(10)",num8, num10);
    }

    return 0;
}