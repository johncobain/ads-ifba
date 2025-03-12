#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct queue{
    Node *head;
    Node *tail;
}Queue;

void enqueue(Queue *q, int val);
int dequeue(Queue *q);
void printQueue(Queue *q);
void freeQueue(Queue *q);

int main(){
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;

    int opt;
    do{
        printf("0 - Sair\n1 - Enfileirar\n2 - Desenfileirar\n3 - Imprimir\n");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            int val;
            printf("Digite o valor :\\> ");
            scanf("%d", &val);
            enqueue(q, val);
            break;
        case 2:
            int ret = dequeue(q);
            printf("%d\n", ret);
            break;
        case 3:
            printQueue(q);
            break;
        case 0:
            
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }while(opt != 0);
    if(q->head != NULL){
        freeQueue(q);
        free(q);
    }

    return 0;
}

void enqueue(Queue *q, int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue *q){
    if(q->head == NULL){
        return -1;
    }
    Node *remove = q->head;
    q->head = remove->next;
    int retVal = remove->val;
    free(remove);
    return retVal;
}

void printQueue(Queue *q){
    Node *current = q->head;
    while(current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue *q){
    Node *current = q->head;
    while(current != NULL){
        Node *remove = current;
        current = current->next;
        free(remove);
    }
    q->head = NULL;
    q->tail = NULL;
}