#include <stdio.h>

int main(){
    int a,b,c, bigger;
    printf("Insira 3 numeros: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b&&a>c){
        bigger = a;
    }else if(b>c&&b>a){
        bigger = b;
    }else{
        bigger = c;
    }
    printf("Maior numero: %d",bigger);

    return 0;
}