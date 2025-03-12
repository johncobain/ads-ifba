#include <stdio.h>

int main(){
    int daysLived, years, months, days, res;
    printf("Type how many days you lived:");
    scanf("%d",&daysLived);
    years = daysLived/365;
    res = daysLived%365;
    printf("%d\n",res);
    months = res/30;
    res = res%30;
    printf("%d\n",res);
    days = res;

    printf("Days Lived: %d\n Years: %d\n Mohtns: %d\n Days: %d", daysLived, years, months, days);
    return 0;
}