/*Um programa para gerenciar os saques de um caixa eletrônico deve possuir algum
mecanismo para decidir o número de notas de cada valor que deve ser disponibilizado
para o cliente que realizou o saque. Um possível critério seria o da "distribuição ótima"
no sentido de que as notas de menor valor fossem distribuídas em número mínimo
possível. Por exemplo, se a quantia solicitada fosse R$ 87,00, o programa deveria indicar
uma nota de R$ 50,00, três notas de R$ 10,00, uma nota de R$ 5,00 e duas notas de R$
1,00. Escreva um programa que receba o valor da quantia solicitada e retorne a
distribuição das notas de acordo com o critério da distribuição ótima (considere existir
notas de R$1,00; R$2,00; R$5,00; R$10,00; R$20,00; R$50,00 e R$100,00).*/
#include <stdio.h>

int main(){
    int dinheiro, notas, n100, n50, n20, n10, n5, n2, n1;
    printf("Valor do saque: R$");
    scanf("%d", &dinheiro);
    notas = dinheiro;

    n100 = notas/100 ;
    notas %= 100;
    n50 = notas/50 ;
    notas %= 50;
    n20 = notas/20 ;
    notas %= 20;
    n10 = notas/10 ;
    notas %= 10;
    n5 = notas/5 ;
    notas %= 5;
    n2 = notas/2 ;
    n1 = notas%2;

    printf("Notas entregues:\n%d notas de R$100.00\n%d notas de R$50.00\n%d notas de R$20.00\n%d notas de R$10.00\n%d notas de R$5.00\n%d notas de R$2.00\n%d notas de R$1.00\n",n100,n50,n20,n10,n5,n2,n1);
    printf("Valor do saque: R$%d.00\n", dinheiro);
    return 0;
}