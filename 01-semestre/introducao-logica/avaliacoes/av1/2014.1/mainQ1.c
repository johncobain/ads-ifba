/*Escreva um algoritmo em linguagem C que leia um número de até três dígitos (menor
ou igual a (777)8) em octal (sistema de numeração base 8) e escreva o seu equivalente
em base 10. Por exemplo, o número (435)8, equivale ao número (285)10. (4*8^2 + 3*8^1 +5*8^0 = 4*64+ 3*8+5*1=256+24+5=285). Demonstre um teste de mesa considerando os
valores indicados (entrada = 435; saída=285). (Valor 2,0)*/
#include <stdio.h>

int main(){
    int num8, d2,d1,d0, num10;
    printf("Insira o numero de tres digitos na base octal (max 777):\\> ");
    scanf("%d", &num8);
    d2 = num8/100;
    d1 = (num8%100)/10;
    d0 = num8%10;
    if(d2>7||d1>7||d0>7||num8/100>=10){
        printf("Valor invalido");
        return 1;
    }
    num10 = d2*64+d1*8+d0;
    printf("O numero (%d)8 equivale ao numero (%d)10",num8, num10);

    return 0;
}