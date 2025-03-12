/*Dado um país A, com 5.000.000 de habitantes e uma taxa de natalidade de 3% ao ano, e
um país B com 7.000.000 de habitantes e uma taxa de natalidade de 2% ao ano, escreva
um programa, que imprima o tempo necessário para que a população do país A ultrapasse
a população do país B
*/
#include <stdio.h>
int main(){
    int a=5000000, b=7000000, count=0;
    while(a<=b){
        printf("Ano %02d---Pais A: %d; Pais B: %d.\n",count, a,b);
        a+=((a/100)*3);
        b+=((b/100)*2);
        count++;
    }
    printf("Ano %02d---Pais A: %d; Pais B: %d.\n",count, a,b);
    printf("Foi necessario %d anos para o pais A ultrapassar o pais B em populacao", count);
    return 0;
}