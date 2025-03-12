#include <stdio.h>

int main(){
    int num, passos;

    scanf("%d", &num);

    for(passos=1; num>1; passos++){
        if(num%2==0){
            num = num/2;
        }else{
            num = (num*3)+1;
        }
    }
    printf("Quantidade de numeros necessarios para chegar em 1: %d",passos);
    return 0;
}