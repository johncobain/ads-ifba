#include <stdio.h>

int main(){
    int Q, P, R; char res;
    printf("Quais sao as posicoes das portinhas Q(cima), P(esquerda) e R(direita)? (0/1) ");
    scanf("%d %d %d",&Q, &P, &R);
    if(Q){
        res = P?'A':'B';
    }else{
        res = R?'C':'D';
    }
    printf("Com as portinhas nas posicoes: Q=%d; P=%d; R=%d;\nA bolinha ira cair pelo caminho %c",Q,P,R,res);
    return 0;
}