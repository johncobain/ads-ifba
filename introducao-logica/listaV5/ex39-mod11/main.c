/*39. O cálculo do DV no módulo 11 é feito, é feito como se segue: para calcular o 
primeiro dígito verificador, cada dígito do
número, começando da direita para a esquerda (do dígito menos significativo para o
dígito mais significativo) é multiplicado, na ordem, por 2, depois 3, depois 4 e assim
sucessivamente, até o primeiro dígito do número. O somatório dessas multiplicações
dividido por 11. O resto desta divisão (módulo 11) é subtraído da base (11), o resultado é
o dígito verificador. O Banco do Brasil utiliza o código módulo 11, substituindo por X o
valor do dígito verificador quando este é 10.
Escreva um programa que receba um
número com os 4 primeiros dígitos de uma agência e imprima o número da agência
completo (numero – dv).
Agência Alg. 1 Alg. 2 Alg. 3 Alg. 4 DV
4870-4 4 8 7 0 (4*5) + (8*4) + (7*3) + (0*2) = 73
73 mod 11 = 7 --- 11-7 = 4
4881-X 4 4 4 1 (4*5) + (8*4) + (8*3) + (1*2) = 78
78 mod 11 = 1 --- 11 – 1 = 10 (X)*/
#include <stdio.h>

int main(){
    int cod, d1,d2,d3,d4, DV;
    printf("Insira os quatro primeiros digitos da sua agencia:\\> ");
    scanf("%d", &cod);
    d1 = cod/1000;
    d2 = (cod%1000)/100;
    d3 = (cod%100)/10;
    d4 = cod%10;

    DV = 11-((d4*2+d3*3+d2*4+d1*5)%11);
    if(DV == 10){
        printf("No. da Agencia: %d-X",cod);
    }else{
        printf("No. da Agencia: %d-%d",cod,DV);
    }
    return 0;
}