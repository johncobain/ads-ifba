#include <stdio.h>

int main(){
    int arr1[10] = {2,3,4,5,6,12,1,23,11,32};
    int arr2[10] = {2,31,4,51,16,12,1,23,111,323};
    int hasNumber, arrSum[10], divisors;
    //part I
    for (int i = 0; i < 10; i++){
        hasNumber = 0;
        for(int j = 0; j<10; j++){
            if(arr1[i] == arr2[j])hasNumber=1;
        }
        if(hasNumber==0)printf("%d ", arr1[i]);
        //part II
        arrSum[i] = arr1[i] + arr2[i];
    }
    printf("\nVetor 1: ");
    for (int i = 0; i < 10; i++)printf("%d ", arr1[i]);
    printf("\nVetor 2: ");
    for (int i = 0; i < 10; i++)printf("%d ", arr2[i]);
    printf("\nVetor Resultado: ");
    for (int i = 0; i < 10; i++)printf("%d ", arrSum[i]);

    //part III
    printf("\nPrimos Vetor 1: ");
    for(int i=0; i<10; i++){
        divisors = 0;
        for(int j=1; j<=arr1[i]; j++) if(arr1[i]%j==0) divisors++;
        if(divisors==2) printf("%d ", arr1[i]);
    }
    printf("\nPrimos Vetor 2: ");
    for(int i=0; i<10; i++){
        divisors = 0;
        for(int j=1; j<=arr2[i]; j++) if(arr2[i]%j==0) divisors++;
        if(divisors==2) printf("%d ", arr2[i]);
    }
    printf("\nPrimos Vetor Resultado: ");
    for(int i=0; i<10; i++){
        divisors = 0;
        for(int j=1; j<=arrSum[i]; j++) if(arrSum[i]%j==0) divisors++;
        if(divisors==2) printf("%d ", arrSum[i]);
    }
    
    return 0;
}