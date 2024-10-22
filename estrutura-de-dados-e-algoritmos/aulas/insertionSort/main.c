#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int * generate_random_integers(int size){
    int * values = malloc(sizeof(int)*size);
    for(int i = 0; i<size; i++){
        values[i] = rand()%101;
    }
    return values;
}

void insertion_sort(int *A, int length){
    for(int j = 1; j< length; j++){
        int key = A[j];
        int i = j-1;
        while(i>=0&& A[i]>key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

void print_array(int *A, int length){
    for(int i = 0; i < length; i++){
        if(i<length-1)printf("%d, ",A[i]);
        else printf("%d.", A[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int length = 7;
    int * values  = generate_random_integers(length);
    printf("Antes\n");
    print_array(values,length);
    insertion_sort(values,length);
    printf("Depois\n");
    print_array(values,length);
    return 0;
}