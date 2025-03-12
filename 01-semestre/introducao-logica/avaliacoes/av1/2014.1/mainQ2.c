/*Questão II
Escreva um algoritmo em linguagem C que leia o horário de entrada (hora, minuto) e o
horário de saída (hora, minuto) de uma aula e escreva o tempo de duração desta aula, no
formato hora:minuto. (Valor 2,5)*/
#include <stdio.h>

int main(){
    int horaE, minutoE, horaS, minutoS, horaT, minutoT;
    printf("Informe a hora e o minuto de entrada(hora minuto):\\> ");
    scanf("%d %d", &horaE, &minutoE);
    printf("Informe a hora e o minuto de saida(hora minuto):\\> ");
    scanf("%d %d", &horaS, &minutoS);
    horaT = horaS - horaE;
    minutoT = minutoS - minutoE;
    horaT *= 60;
    minutoT += horaT;
    horaT = minutoT/60;
    minutoT = minutoT - horaT*60;
    printf("Duracao desta aula: %d:%02d", horaT, minutoT); 
    return 0;
}