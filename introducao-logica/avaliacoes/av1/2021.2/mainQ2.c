/*2) (5.0) - O código de confirmação de uma transação bancária é calculada considerando os quatro dígitos finais do cartão e o horário da transação no formato HHMM. Para o cálculo, são gerados dois números considerando para o primeiro os maiores numerais de cada posição, e para o segundo o menor
númeral de cada posição. Em seguida, o menor número é subtraído do maior e seu invertido é gerado. Este último valor é o código de confirmação da transação.
Por exemplo, para o cartão 4392 e uma transação realizada às 12:15, o código de confirmação será
igual a 3813; calculado da seguinte forma: 4395 - 1212 = 3183, que quando invertido, gera o número
3813.
Escreva um programa em C, que leia um número de quatro dígitos do cartão e um outro representando o horário no formato HHMM e imprima o código de confirmação calculado.*/