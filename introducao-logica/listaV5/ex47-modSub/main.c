#include <stdio.h>

int main(){
    int a,b;
    printf("Insira o valor do dividendo e do divisor (A/B):\\> ");
    scanf("%d %d",&a,&b);
    while(a-b>=0){
        printf("%d - %d = %d\n",a, b, a-b);
        a = a-b;
    }
    printf("%d",a);
    return 0;
}