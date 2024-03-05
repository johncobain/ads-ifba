#include <stdio.h>

int main(){
    int m, i, j;
    printf("Quantas linhas tera a sua meia piramide? ");
    scanf("%d", &m);

    for(i = 1;i<=m;i++){
        for(j=1; j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}