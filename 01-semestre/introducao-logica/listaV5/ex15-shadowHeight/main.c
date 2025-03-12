#include <stdio.h>

int main(){
    float person, personS, building, buildingS, factor;
    printf("Qual e a sua altura?(m) ");
    scanf("%f", &person);
    printf("Qual e o comprimento da sua sombra?(m) ");
    scanf("%f", &personS);

    printf("Qual e o comprimento da sombra do predio?(m) ");
    scanf("%f", &buildingS);

    factor = person/personS;

    building = buildingS*factor;

    printf("Altura do predio: %.2f metros.", building);

    return 0;
}