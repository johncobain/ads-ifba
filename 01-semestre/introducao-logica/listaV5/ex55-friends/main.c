/*Dizemos que dois números são amigos se cada um deles é igual a soma dos divisores
próprios do outro. Os divisores próprios de um número positivo N são todos os divisores
inteiros positivos de N exceto o próprio N. Um exemplo de números amigos são 284 e
220, pois os divisores próprios de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110.
Efetuando a soma destes números obtemos o resultado 284 (1 + 2 + 4 + 5 + 10 + 11 + 20
+ 22 + 44 + 55 + 110 = 284). Os divisores próprios de 284 são 1, 2, 4, 71 e 142,
efetuando a soma destes números obtemos o resultado 220 (1 + 2 + 4 + 71 + 142 = 220).
Escreva um programa que dado dois inteiros, verifique se eles são amigos. (17296 e
18416 são amigos, por exemplo)*/
#include <stdio.h>

int main(){
    int num1, num2, div, sum1To2, sum2To1;
    printf("Digite dois numeros:\\> ");
    scanf("%d %d", &num1, &num2);
    sum1To2 = 0; sum2To1=0;
    for(div=1;div<=num1/2;div++){
        if(num1%div==0){
            sum1To2+=div;
            printf("[%d] ",div);
        }
    }
    printf("= [%d]\n",sum1To2);
    for(div=1;div<=num2/2;div++){
        if(num2%div==0){
            sum2To1+=div;
            printf("[%d] ",div);
        }
    }
    printf("= [%d]\n",sum2To1);
    if(sum1To2==num2&&sum2To1==num1){
        printf("Os numeros %d e %d sao amigos", num1,num2);
    }else{
        printf("Os numeros %d e %d NAO sao amigos", num1,num2);
    }

    return 0;
}