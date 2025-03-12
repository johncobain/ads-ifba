/*Questão IV
Escreva um algoritmo em linguagem C que leia dois valores numéricos, representando
um dia e um mês e escreva a data equivalente por extenso. Por exemplo, se os números
informados forem 02 e 06, a saída deverá ser ‘dois de junho’; caso a data informada seja
01 e 12, a saída deverá ser ‘primeiro de dezembro’. (Valor 2,5)*/
#include <stdio.h>

int main(){
    int dia, mes;
    printf("Insira o dia e o mes do ano em formato numerico:\\> ");
    scanf("%d %d", &dia, &mes);
    switch (dia){
    case 1:printf("Primeiro de ");break;
    case 2:printf("Dois de ");break;
    case 3:printf("Tres de ");break;
    case 4:printf("Quatro de ");break;
    case 5:printf("Cinco de ");break;
    case 6:printf("Seis de ");break;
    case 7:printf("Sete de ");break;
    case 8:printf("Oito de ");break;
    case 9:printf("Nove de ");break;
    case 10:printf("Dez de ");break;
    case 11:printf("Onze de ");break;
    case 12:printf("Doze de ");break;
    case 13:printf("Treze de ");break;
    case 14:printf("Quatorze de ");break;
    case 15:printf("Quinze de ");break;
    case 16:printf("Dezesseis de ");break;
    case 17:printf("Dezessete de ");break;
    case 18:printf("Dezoito de ");break;
    case 19:printf("Dezenove de ");break;
    case 20:printf("Vinte de ");break;
    case 21:printf("Vinte e um de ");break;
    case 22:printf("Vinte e dois de ");break;
    case 23:printf("Vinte e tres de ");break;
    case 24:printf("Vinte e quatro de ");break;
    case 25:printf("Vinte e cinco de ");break;
    case 26:printf("Vinte e seis de ");break;
    case 27:printf("Vinte e sete de ");break;
    case 28:printf("Vinte e oito de ");break;
    case 29:printf("Vinte e nove de ");break;
    case 30:printf("Trinta de ");break;
    case 31:printf("Trinta e um de ");break;
    default:printf("\nDia invalido\n");break;
    }
    switch (mes){
    case 1:printf("Janeiro");break;
    case 2:printf("Fevereiro");break;
    case 3:printf("Marco");break;
    case 4:printf("Abril");break;
    case 5:printf("Maio");break;
    case 6:printf("Junho");break;
    case 7:printf("Julho");break;
    case 8:printf("Agosto");break;
    case 9:printf("Setembro");break;
    case 10:printf("Outubro");break;
    case 11:printf("Novembro");break;
    case 12:printf("Dezembro");break;
    default:printf("\nMes invalido\n");break;
    }

    return 0;
}