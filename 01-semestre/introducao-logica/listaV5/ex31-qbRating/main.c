#include <stdio.h>

int main(){
    int pTent, pComp, pTouch, pInt;
    float jardas, compTent, jardasTent, touchTent, intTent, QBR;
    scanf("%d %d %d %d", &pTent, &pComp, &pTouch, &pInt); scanf("%f", &jardas);
    compTent= ((pComp/(float)pTent)-0.3)/0.2;
    if(compTent<0){compTent = 0;}else if(compTent>2.375){compTent = 2.375;}
    printf("%f\n", compTent);

    jardasTent= ((jardas/(float)pTent)-3)/4;
    if(jardasTent<0){jardasTent = 0;}else if(jardasTent>2.375){jardasTent = 2.375;}
    printf("%f\n", jardasTent);
    
    touchTent= (pTouch/(float)pTent)/0.05;
    if(touchTent<0){touchTent = 0;}else if(touchTent>2.375){touchTent = 2.375;}
    printf("%f\n", touchTent);
    
    intTent= ((pInt/(float)pTent)-0.095)/0.04;
    if(intTent<0){intTent = 0;}else if(intTent>2.375){intTent = 2.375;}
    printf("%f\n", intTent);

    QBR = ((compTent+jardasTent+touchTent+intTent)*100)/6;
    printf("%f\n", QBR);
    return 0;
}