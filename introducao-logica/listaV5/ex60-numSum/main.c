/*A famosa conjectura de Goldbach diz que todo inteiro par maior que 2 é soma de dois
números primos. Testes foram feitos, mas ainda não se achou um contra-exemplo.
Escreva um programa mostrando que a afirmação é verdadeira para todo número par
entre 500 e 1000. O programa deve imprimir o número par e os dois primos que somados
dão o número par.*/
#include <stdio.h>

int main(){
    int num, i, j ,prim1, prim2;
    scanf("%d", &num);
    if(num<=2 || num%2 != 0 || num<500 || num>1000){
        printf("Numero invalido!");
    }else{
        
    }
    return 0;
}