/*Questão	III (4.0)
Para	 se	 determinar	 o	 número	 de	 lâmpadas	 necessárias	 para	 um	 cômodo	 de	 uma	
residência,	 existem	 normas	 que	 dão	 o	 mínimo	 de	 potencia	 de	 iluminação	 exigida	 por	
metro	 quadrado	 (m2),	 conforme	 a	 classe	 deste	 cômodo.	 A	 tabela	 abaixo	 exibe	 estes	
valores

Classe        Utilização    Potência	(W)	/	m2
    I           Quarto              12
                Sala de	TV
    
    II          Sala                15
                Cozinha
                Varanda

    III         Banheiro            20
                Escritório


Suponha	 que	 serão	 usadas	 na	 iluminação	 apenas	 lâmpadas	 de	 60W	 e	 escreva	 um	
programa	em	C,	que	leia	a	classe	de	utilização	do	cômodo	e	suas	dimensões	(largura	e	
comprimento),	 calcule	 e	 imprima	 o	 número	 de	 lâmpadas	 de	 60W	 necessárias	 para	 a	
iluminação	do	cômodo.*/
#include <stdio.h>

int main(){
    float larg, comp, area, lamp; int class;
    printf("Insira a classe de utilizacao do comodo:\\> ");
    scanf("%d",&class);
    printf("Insira a largura e o comprimento do comodo:\\> ");
    scanf("%f %f",&larg, &comp);
    area= larg*comp;
    switch(class){
        case 1:lamp=(area*12)/60;break;
        case 2:lamp=(area*15)/60;break;
        case 3:lamp=(area*20)/60;break;
        default: printf("valor invalido.");
    }
    if(lamp-(int)lamp>0){lamp = (int)lamp+1;}
    printf("Serao necessarias %.0f lampadas de 60W", lamp);
    return 0;
}