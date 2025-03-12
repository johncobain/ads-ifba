#include <stdio.h>

int main(){
    int matriz[5][5], i, j, somaI = 0, somaL = 0, somaC = 0;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j]%2==1){
                somaI += matriz[i][j];
            }
        }
    }
    printf("Soma dos impares: %d\n\n", somaI);
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            somaC+= matriz[i][j];
            somaL+= matriz[j][i];
        }
        printf("Soma da coluna %d: %d\n", j, somaC);
        somaC = 0;
        printf("Soma da linha %d: %d\n\n", j, somaL);
        somaL = 0;
    }
    return 0;
}