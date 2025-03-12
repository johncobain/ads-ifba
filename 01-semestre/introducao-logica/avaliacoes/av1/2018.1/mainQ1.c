#include <stdio.h>

int main(){
    int numBase, d5,d4,d3,d2,d1,d0, count, numParidade;
    scanf("%d", &numBase);
    d1 = numBase%2;
    d2 = (numBase/2)%2;   
    d3 = (numBase/4)%2;   
    d4 = (numBase/8)%2;   
    d5 = (numBase/16)%2;
    count = d5+d4+d3+d2+d1;
    if(count%2==0){
        d0 = 0;
    }else{
        d0 = 1;
    }
    numParidade = d0+(d1*2)+(d2*4)+(d3*8)+(d4*16)+(d5*32);
    printf("%d=>%d",numBase,numParidade);
    return 0;
}