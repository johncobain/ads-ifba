#include <stdio.h>

int main(){
    int fY, fM, fD, fTotal;
    int sY, sM, sD, sTotal;
    printf("Insira o ano, mes e dia (respectivamente) da primeira pessoa e da segunda pessoa (tambem respectivamente):\\> ");
    scanf("%d %d %d %d %d %d",&fY,&fM,&fD,&sY,&sM,&sD);
    fTotal = fD+(fM*30)+(fY*365);
    sTotal = sD+(sM*30)+(sY*365);
    if(fTotal>sTotal){
        printf("A primeira pessoa eh mais velha");
    }else if(sTotal>fTotal){
        printf("A segunda pessoa eh mais velha");
    }else{
        printf("As duas pessoas tem a mesma idade");
    }
    return 0;
}