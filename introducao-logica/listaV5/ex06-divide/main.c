#include <stdio.h>

int main(){
    int n1,n2, quo, res;
    printf("Type the dividend: ");
    scanf("%d", &n1);
    printf("Type the divisor: ");
    scanf("%d", &n2);
    quo = n1/n2;
    res = n1%n2;

    printf("%d | %d", quo, res);
    return 0;
}

