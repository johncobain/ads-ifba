#include <stdio.h>

int main(){
    int num, numSwap, b4, b3, b2, b1, b0;
    int bitS;
    scanf("%d",&num); scanf("%d", &bitS);
    b0 = num%2;
    num = num/2;
    b1 = num%2;
    num = num/2;
    b2 = num%2;
    num = num/2;
    b3 = num%2;
    num = num/2;
    b4 = num%2;

    switch(bitS){
        case 0:
            if(b0==0){b0=1;}else{b0=0;}
        break;
        case 1:
            if(b1==0){b1=1;}else{b1=0;}
        break;
        case 2:
            if(b2==0){b2=1;}else{b2=0;}
        break;
        case 3:
            if(b3==0){b3=1;}else{b3=0;}
        break;
        case 4:
            if(b4==0){b4=1;}else{b4=0;}
        break;
    }
    numSwap = b0+(b1*2)+(b2*4)+(b3*8)+(b4*16);
    printf("%d", numSwap);
    return 0;
}