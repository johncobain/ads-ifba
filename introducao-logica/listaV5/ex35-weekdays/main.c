#include <stdio.h>

int main(){
    int day;
    printf("Insira um numero de 1-7 para retornar o dia da semana: ");
    scanf("%d",&day);
    switch (day)
    {
    case 1:
        printf("Domingo");
        break;
    case 2:
        printf("Segunda");
        break;
    case 3:
        printf("Terça");
        break;
    case 4:
        printf("Quarta");
        break;
    case 5:
        printf("Quinta");
        break;
    case 6:
        printf("Sexta");
        break;
    case 7:
        printf("Sabado");
        break;
    default:
        printf("Numero invalido");
        break;
    }

    return 0;
}