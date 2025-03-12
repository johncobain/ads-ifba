/*Questão I– Valor 2,0
Uma das maneiras de conseguir a raiz quadrada de um número é subtrair do número os ímpares consecutivos a partir
de 1, até que o resultado da subtração seja menor ou igual a zero. O número de vezes que se conseguir fazer esta
subtração é a raiz quadrada exata (quando o resultado da última subtração é 0) ou aproximada do número (quando o
resultado da última subtração é negativo).
Ex,.: Raiz de 16: 16­1 => 15­3 => 12­5 => 7­7 = 0 Logo, a raiz de 16 é 4.
Raiz de 27: 27 – 1 => 26 – 3 => 23 – 5 => 18 – 7 => 11 – 9 => 2 – 11 = ­ 9. Logo, a raiz de 27 é 6.
Escreva em C um algoritmo que use esta técnica para calcular a raiz quadrada (exata ou aproximada) de um número
inteiro.
*/
#include <stdio.h>

int main(){
    int num, base=1, raiz, quadrado=0;

    scanf("%d", &num);
    raiz = num;
    while (raiz>0){
        quadrado++;
        raiz-=base;
        base+=2;
        if(raiz==0)printf("A raiz exata de %d eh %d", num, quadrado);
        else if(raiz<0)printf("A raiz aproximada de %d eh %d",num,quadrado);
    }
    return 0;
}