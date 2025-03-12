/*Um número se diz perfeito se é igual à soma de seus divisores próprios. Divisores
próprios de um número positivo N são todos os divisores inteiros positivos de N exceto o
próprio N. Por exemplo, o número 6, seus divisores próprios são 1, 2 e 3, cuja soma é
igual à 6 (1 + 2 + 3 = 6). Outro exemplo é o número 28, cujos divisores próprios são 1, 2,
4, 7 e 14, e a soma dos seus divisores próprios é 28 (1 + 2 + 4 + 7 + 14 = 28).*/
#include <stdio.h>

int main(){
    int num, div, sum;
    printf("Digite um numero:\\> ");
    scanf("%d", &num);
    sum = 0;
    for(div=1;div<=num/2;div++){
        if(num%div==0){
            sum+=div;
            printf("[%d] ",div);
        }
    }
    printf("= [%d]\n",sum);

    if(sum==num){
        printf("O numero %d eh um numero perfeito", num);
    }else{
        printf("O numero %d NAO eh um numero perfeito", num);
    }

    return 0;
}