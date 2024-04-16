/*. O número e (número de Euler) pode ser representado e calculado por meio da utilização
da série de Taylor para e quando x=1, como a soma da seguinte série infinita: 
e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!*/
#include <stdio.h>

int main(){
    int count, i, n, fac;
    double euler;
    scanf("%d",&n);
    euler = 1; fac = 1;
    for(count=1; count<=n; count++){
        for(i=count; i>=1; i--){
            fac*=i;
        }
        euler += 1.0/fac;
    }
    printf("%lf", euler);

    return 0;
}