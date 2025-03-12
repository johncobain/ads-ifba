#include <stdio.h>
#define QTD_EXP 8

int main(){
    int n=2, mers;
    int numExp = 0;
    int i, divisores;
    while (numExp<QTD_EXP){
        divisores = 0;
        for(i=1;i<=n;i++)if(n%i==0)divisores++;
        if(divisores==2){
            mers = 1;
            for(i=1;i<=n;i++) mers*=2;
            mers-=1;
            divisores=0;
            for(i=1;i<=mers;i++)if(mers%i==0)divisores++;
            if(divisores==2){
                printf("%d %d\n",n, mers);
                numExp++;
            }
        }
        n++;
    }
    return 0;
}