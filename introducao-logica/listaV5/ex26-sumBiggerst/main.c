#include <stdio.h>

int main(){
    float a, b, c;
    float maior, maior2, soma;

    printf("Insira 3 numeros: ");
    scanf("%f %f %f", &a,&b,&c);
    if(a>b&&a>c){
        maior=a;
        if(b>c){maior2 = b;}else{maior2=c;}
    }else if(b>c&&b>a){
        maior =b;
        if(a>c){maior2=a;}else{maior2=c;}
    }else{
        maior = c;
        if(a>b){maior2=a;}else{maior2=b;}
    }
    soma = maior+maior2;
    printf("Soma de %.2f + %.2f = %.2f", maior, maior2, soma);
    return 0;
}