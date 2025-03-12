#include <stdio.h>

int main(){
    int a,b, quo=0;
    printf("Insira o valor do dividendo e do divisor (A/B):\\> ");
    scanf("%d %d",&a,&b);
    while(a-b>=0){
        printf("%d - %d = %d\n",a, b, a-b);
        a = a-b;
        quo++;
    }
    printf("%d",quo);
    return 0;
}