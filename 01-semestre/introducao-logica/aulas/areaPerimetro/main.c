#include <stdio.h>

int main(){
    float base, height, area, per;
    printf("Insira o valor da base: ");
    scanf("%f", &base);
    printf("Insira o valor da altura: ");
    scanf("%f", &height);

    area = base*height;
    per = (base*2)+(height*2);

    printf("Area: %.2f\nPerimetro: %.2f", area, per);

    return 0;
}
