#include <stdio.h>
// 19. Escreva um programa que calcule a raiz de uma equação do primeiro grau.
//
int main(){
    float a, b, c, x;
    printf("Equacao do 1o. grau: ax+b = c\n");
    printf("Insira o valor de a: ");
    scanf("%f", &a);
    printf("Insira o valor de b: ");
    scanf("%f", &b);
    printf("Insira o valor de c: ");
    scanf("%f", &c);
    x = c-((b-(2*b))/a);

    printf("O valor da icognita x e: %.2f",x);

    return 0;
}