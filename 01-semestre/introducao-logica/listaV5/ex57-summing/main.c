#include <stdio.h>

int main(){
    float sum;
    int n, prod, i, j;
    scanf("%d", &n);
    sum = 1;
    for(i = 2; i<=n; i++){
        prod = i;
        for(j=1;j<i;j++){
            prod*=i;
        }
        sum += 1.0/prod;
    }

    printf("%f", sum);

    return 0;
}