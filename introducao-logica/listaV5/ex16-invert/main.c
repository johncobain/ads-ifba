#include <stdio.h>

int main(){
    int num, numIn = 0, c, d, u;
    printf("Insira um numero de 3 algorismos: ");
    scanf("%d", &num);
    c = num/100;
    d = (num%100)/10;
    u = num%10;
    numIn =  u*100+d*10+c;
    
    printf("%d - %d",num, numIn);
    return 0;
}