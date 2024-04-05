#include <stdio.h>

int main(){
    int dec, num,bit;
    long long int bin; 
    long long int base;
    printf("Bota a porra de um numero aqui krl:\\> ");
    scanf("%d",&dec);
    base = 1; bin = 0;
    num = dec;
    while(num>0){
        bit = num%2;
        num /=2;
        bin+= bit*base;
        base*=10;
    }
    // printf("(%d)10 = (%lld)2",dec, bin); //saporra dando erro ai mas funciona
    return 0;
}