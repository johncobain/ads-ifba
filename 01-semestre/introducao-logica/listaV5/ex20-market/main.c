#include <stdio.h>

int main(){
    float preco, entrada, parc;
    printf("Qual eh o preco do produto? R$");
    scanf("%f", &preco);
    entrada = preco/3;
    parc = preco/3;
    entrada += (parc - (int)parc)*2;
    parc = (int)parc;

    printf("\n\n|>Entrada: R$%.2f\n|>Parcelas: R$%.2f\n\n", entrada, parc);

    return 0;
}