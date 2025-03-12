#include <stdio.h>

int main()
{
    float r, area;
    printf("Type the radius of the circunference: ");
    scanf("%f", &r);

    area = 3.14 * (r*r);

    printf(" The area of the circunference is %f", area);
    return 0;
}
