#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct My_Queue{
    int * Q;
    int size;
    int head;
    int tail;
}My_Queue;

void init(My_Queue *q,int size){
    q->Q = malloc(size*sizeof(int));
    q->head = q->tail = 0;
    q->size = size;
}

bool is_empty(My_Queue *q){
    return q->head == q->tail;
}

bool is_full(My_Queue *q){
    return (q->tail+1)%q->size == q->head;
}

void enqueue(My_Queue *q,int x){
    q->Q[q->tail] = x;
    q->tail = (q->tail+1)%q->size;
}

int dequeue(My_Queue *q){
    int x = q->Q[q->head];
    q->head = (q->head+1)%q->size;
    return x;
}

void print_queue(My_Queue *q){
    for( int i = q->head; i != q->tail; i = (i+1)%q->size){
        printf("%d <- ",q->Q[i]);
    }
    printf("\n");
}

int main(){
    My_Queue * fila_lab = malloc(sizeof(My_Queue));
    init(fila_lab, 4);
    enqueue(fila_lab, 10);
    enqueue(fila_lab, 12);
    enqueue(fila_lab, 9);
    print_queue(fila_lab);
    dequeue(fila_lab);
    print_queue(fila_lab);
    dequeue(fila_lab);
    print_queue(fila_lab);
    enqueue(fila_lab, 5);
    print_queue(fila_lab);
    enqueue(fila_lab, 4);
    print_queue(fila_lab);
    return 0;
}