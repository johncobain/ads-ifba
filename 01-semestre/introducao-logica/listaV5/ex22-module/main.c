#include <stdio.h>

int main(){
    float a, mod;
    printf("Insira um numero: ");
    scanf("%f", &a);

    if(a>=0){
        mod = a;
    }else{
        mod = -a;
    }
    printf("|%.2f| = %.2f", a, mod);
}