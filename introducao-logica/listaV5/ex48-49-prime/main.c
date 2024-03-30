#include <stdio.h>

int main(){
    int num, isPrime=1;
    printf("Insira um numero:\\> ");
    scanf("%d", &num);
    for(int i = 2; i<num; i++){
        if(num%i==0)isPrime=0;
    }
    if(isPrime){
        printf("O numero %d eh primo", num);
    }else{
        printf("O numero %d nao eh primo", num);
    }
    return 0;
}