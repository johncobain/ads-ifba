#include <stdio.h>

int main(){
    int cod, b1, b2, b3, b4, b5, prodImpar, valor, DV;
    printf("Insira o codigo de barras de 5 digitos: ");
    scanf("%d", &cod);
    b5 = cod/10000;
    b4 = (cod%10000)/1000;
    b3 = (cod%1000)/100;
    b2 = (cod%100)/10;
    b1 = cod%10;
    prodImpar = 3*(b5+b3+b1);
    valor = prodImpar + b4 + b2;
    DV = 10 - (valor%10);
    printf("Codigo: %d | Digito Verificador: %d", cod, DV);

    return 0;
}