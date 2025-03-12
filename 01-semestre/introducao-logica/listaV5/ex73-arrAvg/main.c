/*Escreva um programa em C que leia um array de 20 inteiros, calcule e imprima:
a. A moda dos elementos no array (elemento mais freqüente).
b. A mediana dos elementos no array (elemento central)
c. A média*/
#include <stdio.h>

int main(){
    int arr[20], cont[20], conta=0, moda, sum=0, i;
    float media, mediana;
    for(i = 0; i<20; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<20; i++){
        sum+=arr[i];
    }

    for(i = 0; i<20; i++){
        for(int j = i+1; j<20; j++){
            if(arr[i]==arr[j]){
                cont[i]++;
                if(cont[i]>conta){
                    conta = cont[i];
                    moda = arr[i];
                }
            }
        }
        cont[i]=0;
    }

    media = sum/20.0;
    mediana = (arr[9]+arr[10])/2.0;

    printf("Moda: %d\nMedia: %.2f\nMediana: %.2f", moda, media, mediana);

    return 0;
}