#include <stdio.h>
#include <math.h> //se tiver uma outra forma eu sinceramente n sei

int main(){
    int i, n; 
    int j, num, primo;
    double sum = 0, pi;
    scanf("%d", &n);
    i=1;
    num =3;
    while(i<=n){
        if(i == 1){
            sum = 1;
            i++;
        }else{
            primo=1;
            for(j=2;j<num;j++){
                if(num%j==0)primo=0;
            }
            if(primo){
                if(i%2==0){
                    sum-= 1.0/(num*num*num);
                }else{
                    sum+= 1.0/(num*num*num);
                }
                i++;
            }
        num++;
        }
    }

    pi = cbrt(sum*32);
    printf("A aprocimacao de PI pelos %d primeiros termos da serie eh: %lf",n, pi);
    return 0;
}