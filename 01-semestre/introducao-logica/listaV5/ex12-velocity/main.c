#include <stdio.h>

int main(){
    float meters, quilometers;
    printf("Type a velocity in m/s: ");
    scanf("%f", &meters);
    quilometers = meters*3.6;

    printf("%.2fm/s is equivalent to %.2fKm/h",meters, quilometers);

    return 0;
}