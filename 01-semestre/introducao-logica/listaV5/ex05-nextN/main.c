#include <stdio.h>

int main(){
    int number;
    printf("Type a number: ");
    scanf("%d", &number);
    printf("The successor of %d is %d", number, number+1);

    return 0;
}