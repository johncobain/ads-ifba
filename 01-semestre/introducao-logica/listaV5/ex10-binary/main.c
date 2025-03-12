#include <stdio.h>

int main(){
    int num, d1,d2,d3,d4,d5;
    int numBinary;
    printf("---------------------\n");
    printf("--DECIMAL-TO-BINARY--\n");
    printf("---------------------\n");
    printf("Type a number less than 32: ");
    scanf("%d",&num);
    d1 = (num%2);
    num/=2;
    d2 = (num%2);
    num/=2;
    d3 = (num%2);
    num/=2;
    d4 = (num%2);
    num/=2;
    d5 = (num%2);
    numBinary = d5*10000+d4*1000+d3*100+d2*10+d1;
    
    printf("%05d", numBinary);
    return 0;
}