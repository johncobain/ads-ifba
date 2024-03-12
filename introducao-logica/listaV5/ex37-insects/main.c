#include <stdio.h>

int main(){
    int type, area, value, valueDesc;
    printf("Qual sera o tipo de pulverizacao?\n\n1 - ervas daninhas\n2 - garfanhotos\n3 - broca\n4 - todos acima\n\\>");
    scanf("%d", &type);
    printf("Qual eh a area a ser pulverizada(em acres)? ");
    scanf("%d", &area);
    switch (type){
    case 1:
        value = 50*area;
        break;
    case 2:
        value = 100*area;
        break;
    case 3:
        value = 150*area;
        break;
    case 4:
        value = 250*area;
        break;
    default:
        printf("Tipo invalido!"); value = 0;
        break;
    }
    if(area>1000){
        value = value - (value*5)/100;
    }
    if(value>750){
        valueDesc = value - 750;
        value = value-valueDesc;
        valueDesc = valueDesc-(valueDesc*10)/100;
        value += valueDesc;
    }

    printf("Valor a ser pago pelo servico: R$%d,00", value);
    return 0;
}