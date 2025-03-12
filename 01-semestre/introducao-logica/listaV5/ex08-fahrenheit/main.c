#include <stdio.h>

int main(){
    float fahrenheit, celsius;
    printf("Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = 5.0f/9.0f*(fahrenheit-32);
    printf("%.1fdeg F is %.1fdeg C", fahrenheit, celsius);
    return 0;
}