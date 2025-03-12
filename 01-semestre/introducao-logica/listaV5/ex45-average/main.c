#include <stdio.h>

int main(){
    float grade, sum, avg;
    int i=1;
    while (i<=5){
        printf("Digite a %do. nota do aluno:\\> ",i);
        scanf("%f",&grade);
        sum+= grade;
        i++;
    }
    avg = sum/5;
    printf("Media: %.2f",avg);
    return 0;
}