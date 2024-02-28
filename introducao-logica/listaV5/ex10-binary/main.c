#include <stdio.h>

int main(){
    int num, i = 0;
    int numBinary[100];
    printf("---------------------\n");
    printf("--DECIMAL-TO-BINARY--\n");
    printf("---------------------\n");
    printf("Type a number less than 32: ");
    scanf("%d",&num);
    if(num < 32){
        while(num >0){
            numBinary[i] = num%2;
            num = num/2;
            i++;
        }
        for(int j = i -1; j >=0; j--){
            printf("%d", numBinary[j]);
        }
    }else{
        printf("Number is greater or equal to 32");
    }
    return 0;
}