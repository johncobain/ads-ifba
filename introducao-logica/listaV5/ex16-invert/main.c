#include <stdio.h>

int main(){
    int num, numIn = 0, cen, dez, uni;
    printf("Insira um numero de 3 algorismos: ");
    scanf("%d", &num);
    cen = num%10;
    num/=10;
    dez = num%10;
    uni = num/10;
    numIn =  cen*100+dez*10+uni;
    printf("%d", numIn);
    return 0;
}