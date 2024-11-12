#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

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


void merge(int *A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = malloc((n1+1)*sizeof(int));
    int *R = malloc((n2+1)*sizeof(int));
    int i, j;
    for(i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    L[n1]= INT_MAX;
    for(j=0; j < n2; j++){
        R[j] = A[q+j+1];
    }
    R[n2]= INT_MAX;
    i=j=0;
    for(int k=p; k<=r; k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}

void merge_sort(int *A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
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
    int length = 500000;
    int * values  = generate_random_integers(length);
    // printf("Antes\n");
    // print_array(values,length);
    clock_t start = clock();
    insertion_sort(values,length);
    // merge_sort(values,0,length-1);
    clock_t end = clock();
    double seconds = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Se passaram %.2f\n", seconds);
    // printf("Depois\n");
    // print_array(values,length);
    return 0;
}