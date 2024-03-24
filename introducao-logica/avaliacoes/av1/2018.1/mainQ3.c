#include <stdio.h>

int main(){
    int timeIn, hour, min, sec, cent, timeOut;
    scanf("%d",&timeIn);
    hour=timeIn/1000000;
    min=(timeIn%1000000)/10000;
    sec=(timeIn%10000)/100;
    cent=timeIn%100;
    printf("%dh %dm %ds %d/100\n",hour, min, sec, cent);
    //transforma tudo em centesimos e volta convertendo
    cent+=(sec*100)+(min*6000)+(hour*360000);
    printf("%d/100\n", cent);
    sec = cent/100;
    cent = cent%100;
    min = sec/100;
    sec = sec%100;
    hour = min/100;
    min = min%100;
    printf("%dh %dm %ds %d/100\n",hour, min, sec, cent);

    timeOut = cent + (sec*100)+(min*10000)+(hour*1000000);
    printf("%d",timeOut);
    return 0;
}