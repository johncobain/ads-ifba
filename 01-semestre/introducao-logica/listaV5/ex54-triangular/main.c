#include <stdio.h>

int main(){
    int num, i;
    scanf("%d", &num);
    for(i=1;i<=num/2;i++){
        if(i*(i+1)*(i+2)==num){
            printf("O numero %d eh triangular: %dx%dx%d=%d",num,i,i+1,i+2,num);
            break;
        }
        if(i == num/2) printf("O numero %d nao eh triangular", num);
    }
    return 0;
}