#include <stdio.h>

int main(){
    int num, d1,d0, sum;
    scanf("%d",&num);
    if(num<=9999&&num>999){
        d1=(num%1000)/100; d0 = (num%100)/10;
    }else if(num<=999 && num>99){
        d1 =(num%100)/10; d0 = 0;
    }else if(num<=99 && num >9){
        d1 = (num%100)/10; d0 = num%10;
    }else if (num<=9 && num>=0){
        d1 = num; d0 = 0;
    }else{
        d1 = 0; d0 = 0; printf("Numero invalido!");
    }
    sum = d1 + d0;
    printf("soma dos elementos centrais: %d", sum);
    return 0;
}