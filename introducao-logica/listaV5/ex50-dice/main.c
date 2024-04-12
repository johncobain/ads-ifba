#include <stdio.h>
#define QNT_LADOS 20

int main(){
    int num, i, j, k;
    printf("Insira um numero:\\> ");
    scanf("%d",&num);
    for(i=1;i<=QNT_LADOS;i++){
        for(j=1;j<=QNT_LADOS;j++){
            for(k=1;k<=QNT_LADOS;k++){
                if(i+j+k==num){
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }

    return 0;
}