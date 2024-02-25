#include <stdio.h>

int main(){
    float s1,s2,s3, p;
    printf("Type one of the sides of the triangle: ");
    scanf("%f", &s1);
    printf("Type the second side of the triangle: ");
    scanf("%f", &s2);
    printf("Type the third side of the triangle: ");
    scanf("%f", &s3);

    p = s1+s2+s3;

    printf("The perimeter of the triangle is %f", p);

    return 0;
}