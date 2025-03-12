#include <stdio.h>

int main(){
    int num1;
    printf("Informe um numero:\\> ");
    scanf("%d", &num1);

    if(num1>0){
        printf("Positivo");
    }else if(num1<0){
        printf("Negativo");
    }else{
        printf("Zero");
    }
    return 0;
}