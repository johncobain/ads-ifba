#include <stdio.h>

int main(){
    float sal, desc;
    printf("Insira o seu salario: ");
    scanf("%f", &sal);
    desc = (sal*11)/100;
    if(desc > 334.29){
        desc = 334.29;
    }
    printf("Desconto previdenciario: R$%.2f", desc);

    return 0;
}