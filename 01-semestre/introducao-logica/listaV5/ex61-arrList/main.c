#include <stdio.h>

int main(){
    int arr[20];
    for(int i = 0; i<20; i++){
        arr[i] = 0;
    }

    for(int j = 0; j<20; j++){
        printf("%02do. - %d\n",j, arr[j]);
    }
    return 0;
}