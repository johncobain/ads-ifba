#include <stdio.h>

int main(){
    float radius, height, volume;
    printf("Type the radius of the oil can: ");
    scanf("%f", &radius);
    printf("Type the height of the oil can: ");
    scanf("%f", &height);
    volume = (3.14*(radius*radius))*height;
    printf("The volume of the oil can is %.2f", volume);
    return 0;
}