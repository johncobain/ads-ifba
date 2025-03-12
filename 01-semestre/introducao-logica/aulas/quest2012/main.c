#include <stdio.h>

int main(){
    int num, met1, met2, sum, pot;

    for(num=0;num<=9999;num++){
        met1 = num/100;
        met2 = num%100;
        sum = met1+met2;
        pot = sum*sum;
        
        if(pot==num)printf("%04d\n",num);
    }

    return 0;

}