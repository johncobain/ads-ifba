#include <stdio.h>
#include <windows.h>

int main(){
    int num;
    printf("-----------------------------\n");
    printf("-------NUMBER--GUESSER-------\n");
    printf("-----------------------------\n");
    printf("Type a number: ");
    scanf("%d", &num);
    printf("Loading recourses...\n");
    Sleep(1000);
    printf("Searching in memory...\n");
    Sleep(2000);
    printf("Looking online...\n");
    Sleep(2000);
    printf("Guessing number...\n");
    Sleep(2000);
    printf("Your number is...\n");
    Sleep(1500);
    printf("---------------%d---------------", num);
    Sleep(1000);
    return 0;
}