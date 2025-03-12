/*Questão III - Valor 4.0
Bruninho está programando um personagem virtual para o próximo desafio de um jogo
de aventura em que, numa das fases, o personagem tem que entrar em um corredor,
percorrer algumas salas e depois sair do corredor. Ele pode entrar apenas uma vez, e
passar por cada sala apenas uma vez. Todas as salas possuem uma porta de entrada e
uma de saída. Ao passar por uma sala o jogador ganha um certo número de vidas (que
pode ser negativo!). O objetivo é passar pelo corredor coletando a maior quantidade
possível de vidas! Por sorte, sempre existe ao menos uma sala onde se ganha um
número positivo de vidas.
 0 1  2 3   4 5 6
-2 5 -1 8 -11 7 3
No exemplo acima, o personagem de Bruninho pode ganhar, no máximo, 12 vidas, por
exemplo, entrando pela sala 1 e saindo pela sala 3 (5-1+8 = 12). Você deve escrever um
programa que, leia o número de vidas correspondentes a cada sala do corredor (o
corredor possui dez salas), calcule e imprima a quantidade máxima de vidas que será
possível ganhar.*/
#include <stdio.h>

int main(){
    int salas[10], i, j;
    int tot, max;
    for(i=0;i<10;i++){
        printf("Insira o valor da sala %d:\\> ",i);
        scanf("%d", &salas[i]);
    }
    for(i=0;i<9;i++){
        tot = salas[i];
        for(j=i+1;j<10;j++){
            tot+= salas[j];
            if(i==0&&j==1)max=tot;
            else if(tot>max)max=tot;
        }
    }
    printf("Quantidade maxima de vidas: %d", max);
    return 0;
}