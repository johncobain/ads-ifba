#include <stdio.h>

int main(){
    float height, mass, imc;
    printf("Massa (Kg): ");
    scanf("%f", &mass);
    printf("Altura (m): ");
    scanf("%f", &height);
    imc = mass/(height*height);
    printf("Seu IMC eh de: %.2f\n", imc);
    if(imc >= 18.5 && imc < 25){
        printf("Peso Ideal!");
    }else{
        printf("Nao esta no peso ideal!");
    }

    return 0;
}