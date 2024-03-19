/*2) (5.0) - O código de confirmação de uma transação bancária é calculada considerando os quatro dígitos finais do cartão e o horário da transação no formato HHMM. Para o cálculo, são gerados dois números considerando para o primeiro os maiores numerais de cada posição, e para o segundo o menor
númeral de cada posição. Em seguida, o menor número é subtraído do maior e seu invertido é gerado. Este último valor é o código de confirmação da transação.
Por exemplo, para o cartão 4392 e uma transação realizada às 12:15, o código de confirmação será
igual a 3813; calculado da seguinte forma: 4395 - 1212 = 3183, que quando invertido, gera o número
3813.
Escreva um programa em C, que leia um número de quatro dígitos do cartão e um outro representando o horário no formato HHMM e imprima o código de confirmação calculado.*/
#include <stdio.h>

int main(){
    int cart, hora, valorMa=0, valorMe=0, sub, d3,d2,d1,d0, cod;
    scanf("%d %d", &cart, &hora);
    if(cart%10>hora%10){valorMa+=cart%10; valorMe+=hora%10;}
    else{valorMa=hora%10; valorMe=cart%10;}
    if((cart%100)/10>(hora%100)/10){valorMa+=((cart%100)/10)*10; valorMe+=((hora%100)/10)*10;}
    else{valorMa+=((hora%100)/10)*10; valorMe+=((cart%100)/10)*10;}
    if((cart%1000)/100>(hora%100)/100){valorMa+=((cart%1000)/100)*100; valorMe+=((hora%1000)/100)*100;}
    else{valorMa+=((hora%1000)/100)*100; valorMe+=((cart%1000)/100)*100;}
    if(cart/1000>hora/1000){valorMa+=(cart/1000)*1000;valorMe+=(hora/1000)*1000;}
    else{valorMa+=(hora/1000)*1000; valorMe+= (cart/1000)*1000;}
    sub = valorMa - valorMe;
    d3 = sub/1000;
    d2 = (sub%1000)/100;
    d1 = (sub%100)/10;
    d0 = sub%10;

    printf("\n%d\n%d\n%d\n%d %d %d %d\n",valorMa,valorMe, sub, d3, d2, d1, d0);
    cod = d3 + (d2*10) + (d1*100) + (d0*1000);
    printf("%04d", cod);

    return 0;
}