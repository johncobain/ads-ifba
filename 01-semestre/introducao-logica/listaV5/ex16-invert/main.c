#include <stdio.h>

int main(){
    int num, numIn = 0, c, d, u;
    printf("Insira um numero de 3 algorismos:\\> ");
    scanf("%d", &num); //suponha num =431
    c = num/100; //431/100 = 4
    d = (num%100)/10; //431%100 = 31| 31/10 = 3
    u = num%10; // 431%10 = 1
    numIn =  u*100+d*10+c;

    printf("%03d - %03d",num, numIn);
    return 0;
}