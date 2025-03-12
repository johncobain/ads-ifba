/*2) (5.0) - O código de confirmação de uma transação bancária é calculada considerando os quatro dígitos finais do cartão e o horário da transação no formato HHMM. Para o cálculo, são gerados dois números considerando para o primeiro os maiores numerais de cada posição, e para o segundo o menor
númeral de cada posição. Em seguida, o menor número é subtraído do maior e seu invertido é gerado. Este último valor é o código de confirmação da transação.
Por exemplo, para o cartão 4392 e uma transação realizada às 12:15, o código de confirmação será
igual a 3813; calculado da seguinte forma: 4395 - 1212 = 3183, que quando invertido, gera o número
3813.
Escreva um programa em C, que leia um número de quatro dígitos do cartão e um outro representando o horário no formato HHMM e imprima o código de confirmação calculado.*/
#include <stdio.h>

int main(){
    int cart, hora, c3, c2, c1, c0, h3, h2, h1, h0;
    int valorMa=0, valorMe=0, sub, d3,d2,d1,d0, cod;
    scanf("%d %d", &cart, &hora);
    c3 = cart/1000;
    c2 = (cart%1000)/100;
    c1 = (cart%100)/10;
    c0 = cart%10;

    h3 = hora/1000;
    h2 = (hora%1000)/100;
    h1 = (hora%100)/10;
    h0 = hora%10;

    if(c0>h0){
        valorMa+=c0; 
        valorMe+=h0;
    }else{
        valorMa=h0; 
        valorMe=c0;
    }

    if(c1>h1){
        valorMa+=(c1)*10; 
        valorMe+=(h1)*10;
    }else{
        valorMa+=(h1)*10; 
        valorMe+=(c1)*10;
    }
    
    if(c2>h2){
        valorMa+=(c2)*100; 
        valorMe+=(h2)*100;
    }else{
        valorMa+=(h2)*100; 
        valorMe+=(c2)*100;
    }

    if(c3>h3){
        valorMa+=(c3)*1000;
        valorMe+=(h3)*1000;
    }else{
        valorMa+=(h3)*1000; 
        valorMe+= (c3)*1000;
    }
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