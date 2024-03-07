#include <stdio.h>

int main(){
    char num[10], numInv[10];
    int i, j;
    printf("Type a number with 3 digits: ");
    scanf("%s", num);
    j = 2;
    for(i = 0; i<3; i++){
        numInv[i] = num[j];
        j--;
        printf("%c --- %c\n", num[i], numInv[i]);
    }

    return 0;
}