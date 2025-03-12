/*. A série de FETUCCINE é gerada da seguinte forma: os dois primeiros termos são
fornecidos pelo usuário; a partir daí, os termos são gerados com a soma ou subtração dos
dois termos anteriores, ou seja:
1. Ai = Ai-1 + Ai-2, para i ímpar
2. Ai = Ai-1 - Ai-2, para i par
Criar um algoritmo que imprima os N primeiros termos da série de FETUCCINE, sabendo-se que para existir esta série serão necessários pelo menos três
termos. */
#include <stdio.h>

int main(){
    int n, atual, term1, term2;
    printf("Insira os dois primeiros termos e a quantidade de termos desejados:\\>");
    scanf("%d %d %d",&term1, &term2, &n);
    if(n<3){
        printf("Quantidade de termos invalida");
    }else{
        printf("1o.: %d\n2o.: %d\n",term1, term2);
        for(int i = 3; i<=n; i++){
            if(i%2==0){
                atual = term1 + term2;
            }else{
                atual = term1-term2;
            }
            printf("%do.: %d\n",i,atual);
            term1 = term2;
            term2 = atual;
        }
    }

    return 0;
}