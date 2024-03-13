#include <stdio.h>

int main(){
    int num1, num2, maior;
    printf("Informe dois numeros:\\> ");
    scanf("%d %d", &num1, &num2);

    maior = num1>num2? num1:num1==num2?-1:num2;

    printf("%d",maior);
    return 0;
}