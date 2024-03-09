#include <stdio.h>

int main(){
    int month;
    printf("Insira o numero referente a um mes do ano(1-12): ");
    scanf("%d", &month);

    switch(month){
        case 1:
            printf("Mes %d: JANEIRO", month);
        break;
        case 2:
            printf("Mes %d: FEVEREIRO", month);
        break;
        case 3:
            printf("Mes %d: MARCO", month);
        break;
        case 4:
            printf("Mes %d: ABRIL", month);
        break;
        case 5:
            printf("Mes %d: MAIO", month);
        break;
        case 6:
            printf("Mes %d: JUNHO", month);
        break;
        case 7:
            printf("Mes %d: JULHO", month);
        break;
        case 8:
            printf("Mes %d: AGOSTO", month);
        break;
        case 9:
            printf("Mes %d: SETEMBRO", month);
        break;
        case 10:
            printf("Mes %d: OUTUBRO", month);
        break;
        case 11:
            printf("Mes %d: NOVEMBRO", month);
        break;
        case 12:
            printf("Mes %d: DEZEMBRO", month);
        break;
        default:
            printf("Numero invalido!");
        break;
    }

    return 0;
}