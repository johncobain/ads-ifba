#include <stdio.h>

int main(){
    int n, num=1,numPrev=0, aux;
    printf("Insira a quantidade de numeros na seria fibonacci:\\> ");
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        printf("%d ",num);
        aux = num;
        num+= numPrev;
        numPrev = aux;
    }
    return 0;
}