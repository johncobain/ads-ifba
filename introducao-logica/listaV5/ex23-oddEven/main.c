#include <stdio.h>

int main(){
    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);

    if(num%2 == 0){
        printf("%d e um numero par!", num);
    }else{
        printf("%d e um numero impar!", num);
    }
    return 0;
}