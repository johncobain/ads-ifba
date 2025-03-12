#include <stdio.h>

int main(){
    int limite, cod, opr1, opr2, operacao, res;

    scanf("%d", &limite);
    scanf("%d",&cod);
    opr2 = cod%1000;
    cod -= opr2;
    operacao = (cod%10000)/1000;
    cod -= operacao*1000;
    opr1 = cod/10000;
    switch (operacao){
    case 1:
        res = opr1+opr2;
    break;
    case 2:
        res = opr1-opr2;
    break;
    case 3:
        res = opr1*opr2;
    break;
    case 4:
        res = opr1/opr2;
    break;
    }
    if(res<=limite){
        printf("%d",res);
    }else{
        printf("Overflow");
    }
    return 0;
}