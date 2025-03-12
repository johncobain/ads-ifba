#include <stdio.h>

int main(){
    float renda, emprestimo, parcelas; int prestacoes;
    scanf("%f", &renda);scanf("%f", &emprestimo);scanf("%d", &prestacoes);
    if(emprestimo>renda*10){printf("Emprestimo negado!");}
    else{
        parcelas = emprestimo/prestacoes;
        if(parcelas> (renda*30)/100){printf("Emprestimo negado!");}
        else{
            printf("Emprestimo de R$%.2f concedido!\nPagamento: %d parcelas de R$%.2f",emprestimo,prestacoes,parcelas);
        }
    }
    return 0;
}