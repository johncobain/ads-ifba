#include <stdio.h>

int main(){
    int num, count;
    printf("Insira um numero entre 0 e 32:\\> ");
    scanf("%d", &num);
    count = num%2;
    count += (num/2)%2;
    count += (num/4)%2;
    count += (num/8)%2;
    count += (num/16)%2;
    count += (num/32)%2;
    printf("O numero %d tem %d 1\'s em sua representacao binaria.",num, count);
    return 0;
}