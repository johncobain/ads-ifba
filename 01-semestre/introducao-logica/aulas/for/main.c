#include <stdio.h>

int main(){
    int i,j;

    // for(x=0,y=1; x<10&&y<15;x++,y+=2){
    //     printf("%d ",x+y);
    // }
    for(i=0; i<=5; i++){
        for(j=0; j<=5;j++){
            printf("[%d, %d] ",i,j);
        }
        printf("\n\n");
    }
}