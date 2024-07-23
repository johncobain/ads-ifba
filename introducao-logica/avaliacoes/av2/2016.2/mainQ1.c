/*Questão I (3.5)
Um número primo é um número que possui somente dois divisores: ele mesmo e o
número 1. Um número primo p é um número primo de Chen se o próximo número
ímpar (p + 2) é primo ou o produto de dois primos (subprimo).
Escreva um programa em C, que leia um número e verifique se ele é um número primo
de Chen. Por exemplo,
2 é um primo de Chen, pois 2+2 = 4 e 4 é subprimo (2*2).
3 é um primo de Chen, pois 3+2 = 5 e 5 é primo.*/
#include <stdio.h>

int main(){
    int num, shein;
    int i, primo1, primo2, divisores, subprimo=0;

    scanf("%d", &num);
    
    divisores=0;
    for(i=1;i<=num;i++) if(num%i==0)divisores++;
    if(divisores<=2){
        divisores = 0;
        shein = num+2;
        for(i=1;i<=shein;i++) if(shein%i==0)divisores++;
        if(divisores<=2){
            printf("%d eh um primo de Chen, pois %d + 2 = %d e %d eh primo",num, num, shein, shein);
        }else{
            for(primo1=2; primo1<=shein/2&&subprimo==0;primo1++){
                divisores=0;
                for(i=1;i<=primo1;i++) if(primo1%i==0)divisores++;
                if(divisores<=2){
                    for(primo2=2; primo2<=shein/2&&subprimo==0;primo2++){
                        divisores=0;
                        for(i=1;i<=primo2;i++) if(primo2%i==0)divisores++;
                        if(divisores<=2){
                            if(primo1*primo2==shein)subprimo=1;
                        }
                    }
                }
            }
            if(subprimo==1){
                printf("%d eh um primo de Chen, pois %d + 2 = %d e %d eh subprimo(%dx%d)",num, num, shein, shein,primo1-1,primo2-1);
            }else{
                printf("%d NAO eh um primo de Chen",num);
            }
        }
    }else{
        printf("%d nao eh um numero primo",num);
    }

    return 0;
}