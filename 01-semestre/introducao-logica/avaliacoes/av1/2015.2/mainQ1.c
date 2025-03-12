// a) conta da mesa: float conta Total; quantidade de pessoas: int qntPessoas;
// b) valor por pessoa: float contaPessoa;
// c) /*código/

#include <stdio.h>

int main(){
    float contaTotal, contaPessoa, taxa;
    int qntPessoas;
    printf("Qual foi o valor total da conta? R$"); scanf("%f", &contaTotal);
    printf("Quantas pessoas irao pagar? "); scanf("%d", &qntPessoas);
    contaPessoa = contaTotal/qntPessoas;
    taxa = (contaPessoa*10)/100;
    contaPessoa += taxa;
    printf("Cada pessoa devera pagar R$%.2f", contaPessoa);
    return 0;
}