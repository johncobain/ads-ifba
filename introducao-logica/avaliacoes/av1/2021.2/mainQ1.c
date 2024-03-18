/*1) (5.0) - Diferente dos computadores binários tradicionais, que fazem representações numéricas
usando dígitos binários, os computadores ternários balanceados fazem sua representação numérica
através de dígitos ternários balanceados ou trits.
No sistema de numeração ternário balanceado, de forma similar aos sistemas de representação tradicionais, os valores numéricos são posicionais. Nesse caso, a base aplicada é a base três. Assim, o dígito
mais à direita vale um, contudo, deslocá-lo uma posição à esquerda, equivale a multiplicá-lo por três.
Existem três trits possíveis: 2, 1 e 0. O trit 2 adiciona o valor posicional correspondente, o 1 não adiciona nem subtrai e o 0, subtrai o valor em questão. Por exemplo: o número 222 em ternário balanceado equivale a: 9 + 3 + 1 = 13. Já o número 2010, equivale a 27-9+0-1=17.
Escreva um programa em C, que leia um número de até quatro trits e imprima o seu equivalente em
decimal.*/
#include <stdio.h>

int main(){
    int num3, t3,t2,t1,t0, num10;
    printf("Insira um numero de 4 trits:\\> "); scanf("%d", &num3);
    t3 = num3/1000;
    t2 = (num3%1000)/100;
    t1 = (num3%100)/10;
    t0 = num3%10;
    switch(t0){
        case 2: t0=1;break;
        case 1: t0=0;break;
        case 0: t0=-1;break; default: t0=0;
    }
    switch(t1){
        case 2: t1=3;break;
        case 1: t1=0;break;
        case 0: t1=-3;break; default: t1=0;
    }
    switch(t2){
        case 2: t2=9;break;
        case 1: t2=0;break;
        case 0: t2=-9;break; default: t2=0;
    }
    switch(t3){
        case 2: t3=27;break;
        case 1: t3=0;break;
        case 0: t3=-27;break; default: t3=0;
    }
    num10 = t3+t2+t1+t0;
    printf("%04d em ternario balanceado eh igual a %d em decimal.",num3, num10);
    return 0;
}