#include <stdio.h>
#define DIM 5

int main(){
    int matriz[DIM][DIM];
    int i,j;
    int sum=0, prod=1;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            matriz[i][j]=(i*DIM)+j+1;
            if(i==j)sum+=matriz[i][j];
            if(i+j==DIM-1)prod*=matriz[i][j];
        }

    }
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            printf("%02d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("Somatorio: %d\nProdutorio: %d",sum, prod);
    

    return 0;
}