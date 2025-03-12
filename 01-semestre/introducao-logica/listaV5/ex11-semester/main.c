#include <stdio.h>

int main(){
    float n1,n2,b1,b2,semestre;
    printf("Digite as notas das duas avaliacoes do primeiro bimestre: ");
    scanf("%f %f", &n1, &n2);
    b1 = n1 + n2;

    printf("Digite as notas das duas avaliacoes do segundo bimestre: ");
    scanf("%f %f", &n1, &n2);
    b2 = n1 + n2;

    semestre = (b1+b2)/2;
    printf("Nota semestral: %.2f", semestre);
    return 0;
}