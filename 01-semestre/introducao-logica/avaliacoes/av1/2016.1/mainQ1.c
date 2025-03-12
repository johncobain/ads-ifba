/*Questão	I (2.0)
Escreva um	programa	 em	 C	 que	 calcule o	 desconto	 previdenciário	 de	 um	 funcionário.	
Dado	 um	 salário,	 o	 programa	 deve	 imprimir o	 valor	 do	 desconto	 proporcional	 ao	
mesmo.	O	cálculo	segue	a	regra:	o	desconto	é	de	11%	do	valor	do	salário,	entretanto, o	
valor	máximo	de	desconto	é	570,88.	*/
#include <stdio.h>

int main(){
    float sal, desc;
    printf("Insira seu salario:\\>R$");
    scanf("%f",&sal);
    desc = (sal*11)/100;
    if(desc>570.88) desc = 570.88;
    printf("Desconto Previdenciario: R$%.2f",desc);

    return 0;
}