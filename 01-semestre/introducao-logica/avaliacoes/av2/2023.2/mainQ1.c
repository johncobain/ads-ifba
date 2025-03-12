#include <stdio.h>
#define QTDE_NUM 128

int main(){
    int arr[QTDE_NUM];
    int sentinela = 0;
    int num = 0, soma = 0, i;
    for(i=0; i<QTDE_NUM&&num>=0; i++){
        scanf("%d",&num);
        if(num>0){
            arr[sentinela] = num;
            sentinela++;
        }else if(num==0){
            sentinela--;
        }
    }
    for(i=0;i<sentinela;i++){
        soma+=arr[i];
    }
    printf("Resultado: %d", soma);
    return 0;
}