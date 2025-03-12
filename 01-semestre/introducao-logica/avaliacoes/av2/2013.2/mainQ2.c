/*Questão II– Valor 3,0
Números primos gêmeos na teoria dos números são dois números primos cuja diferença é igual a dois. Os primeiros
pares de números primos gêmeos são (3, 5), (5, 7), (11, 13), (17, 19), (29, 31) e (41, 43).
Escreva um programa em C que imprima os primeiros N pares de números primos, onde N é uma entrada para o
programa em questão.
*/
#include <stdio.h>

int main(){
    int num, termo=0, i, j, n=2, divisores;

    scanf("%d", &num);
    while (termo<num){
        divisores=0;
        for(i=1;i<n;i++)if(n%i==0)divisores++;
        if(divisores<2){
            divisores=0;
            for(j=1;j<n+2;j++)if((n+2)%j==0)divisores++;
            if(divisores<2){
                printf("(%d, %d)",n,n+2);
                termo++;
            }
        }
        n++;
    }
    return 0;
}