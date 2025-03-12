#include <stdio.h>

int main(){
    float num1, num2, num3, media;
    scanf("%f %f %f", &num1, &num2, &num3);
    if(num1>num2&&num1>num3){media= (num1*5+num2*2.5+num3*2.5)/10;}
    else if(num2>num1&&num2>num3){media= (num2*5+num1*2.5+num3*2.5)/10;}
    else{media= (num3*5+num2*2.5+num1*2.5)/10;}
    printf("%f", media);
    return 0;
}