#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *arr;
    int head;
    int tail;
    int size;
    int count;
}Queue;

void initQueue(Queue *q, int size){
    q->arr = malloc(sizeof(int) * size);
    q->size = size;
    q->head = 0;
    q->tail = 0;
}

void enqueue(Queue *q, int val){
    if((q->tail+1) % q->size == q->head){
        printf("Queue is full\n");
        return;
    }
    q->arr[q->tail] = val;
    q->tail = (q->tail + 1) % q->size;    
}

int dequeue(Queue *q){
    if (q->head == q->tail) { // Fila vazia
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->head];
    q->head = (q->head +1) % q->size;
    return val;
}

void printQueue(Queue *q){
    if (q->head == q->tail) { // Fila vazia
        printf("Queue is empty\n");
        return;
    }
    int current = q->head;
    while(current != q->tail){
        printf("%d -> ", q->arr[current]);
        current = (current + 1) % q->size;
    }
    printf("%d\n", q->arr[current]);
}

int main(){
    Queue *q = malloc(sizeof(Queue));
    initQueue(q, 10);

    // Teste de enfileiramento
    for (int i = 0; i <= 12; i++) {
        enqueue(q, i);
    }

    printQueue(q);

    // Teste de desenfileiramento
    for (int i = 0; i < 3; i++) {
        dequeue(q);
    }

    printQueue(q);

    // Teste de desenfileiramento
    for (int i = 0; i < 10; i++) {
        dequeue(q);
    }

    printQueue(q);

    free(q->arr);    
    free(q); 
    return 0;
}