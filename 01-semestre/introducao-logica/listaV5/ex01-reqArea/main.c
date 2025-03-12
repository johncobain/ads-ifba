#include <stdio.h>

int main()
{
    int num1;
    printf("Type the length of the base of your reqtangle: \n");
    scanf("%d", &num1);
    int num2;
    printf("Type the length of the height of your reqtangle: \n");
    scanf("%d", &num2);

    printf("Your reqtangle has an area of %d", num1*num2);
    return 0;
}
