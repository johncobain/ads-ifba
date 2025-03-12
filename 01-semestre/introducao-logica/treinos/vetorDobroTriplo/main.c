#include <stdio.h>

int main(){
    int vetO[30], vetC[30];
    int i;

    for(i=0; i<30; i++){
        scanf("%d", &vetO[i]);
    }
    for(i=0; i<30; i++){
        if(i%2==0){
            vetC[i]= 2*vetO[i];
        }else{
            vetC[i]= 3*vetO[i];
        }
        printf("%d-%d\n", vetO[i], vetC[i]);
    }
    return 0;

}