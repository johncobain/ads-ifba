#include <stdio.h>

int main(){
    char fuel;
    float qnt, price, desc;
    printf("Qual combustivel deseja utilizar?\n(A) - Alcool\n(G) - Gasolina\n");
    scanf("%c", &fuel);
    printf("Quantos litros deseja abastecer? ");
    scanf("%f", &qnt);
    if(fuel == 'A'){
        price = qnt*1.9;
        desc = (qnt<=25)?(price*2)/100:(price*4)/100;
        price -= desc;
    }else if(fuel == 'G'){
        price = qnt*2.7;
        desc = (qnt<=25)?(price*3)/100:(price*5)/100;
        price -= desc;
    }else{price = 0;}
    printf("Valor a ser pago: R$%.2f", price);
    return 0;
}