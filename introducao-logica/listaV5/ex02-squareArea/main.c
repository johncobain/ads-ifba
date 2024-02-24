#include <stdio.h>

int main(){
    float side, area;

    printf("Type the length of the side of your square: ");
    scanf("%f", &side);

    area = side*side;

    printf("The area of your square is %f", area);

    return 0;
}