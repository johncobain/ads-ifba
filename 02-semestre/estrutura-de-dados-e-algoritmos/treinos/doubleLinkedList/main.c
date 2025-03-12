#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no *next;
    struct no *prev;
}No;

void initList(No *l){
    l = (No*)malloc(sizeof(No));
    l->next = NULL;
    l->prev = NULL;
}
int push(No **l, int val);
int pop(No **l);
int unshift(No **l, int val);
int shift(No **l);

int insert(No **l, int val, int index);
int removeL(No **l, int index);

void printList(No *l);

int menu(){
    int opt;
    printf("------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Unshift\n");
    printf("4. Shift\n");
    printf("5. Insert\n");
    printf("6. Remove\n");
    printf("7. Print\n");
    printf("0. Exit\n");
    printf("Option: ");
    scanf("%d", &opt);
    return opt;
}

int main(){
    No *list = NULL;
    initList(list);
    int opt;
    do{
        int val, retVal, len, index;
        opt = menu();
        switch(opt){
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    len = push(&list, val);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 2:
                system("clear");
                retVal = pop(&list);  
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    len = unshift(&list, val);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 4:
                system("clear");
                retVal = shift(&list);  
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 5:
                printf("Value: ");
                scanf("%d", &val);
                printf("Index: ");
                scanf("%d", &index);
                system("clear");
                if(val >= 0 && index >= 0){
                    len = insert(&list, val, index);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 6:
                printf("Index: ");
                scanf("%d", &index);
                system("clear");
                if(index >= 0){
                    len = removeL(&list, index);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid index\n");
                }
                break;
            case 7:
                system("clear");
                printList(list);
                break;
            case 0:
                
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }while(opt != 0);

    return 0;
}

void printList(No *l){
    if(l != NULL){    
        while(l != NULL){
            printf("%d -> ", l->val);
            l = l->next;
        }
        printf("NULL\n");
    }else{
        printf("List is empty\n");
    }
}

int push(No **l, int val){
    int len = 1;
    No *currentL = *l;
    No *newL = malloc(sizeof(No));
    if(currentL == NULL){
        newL->val = val;
        newL->next = NULL;
        newL->prev = NULL;
        *l = newL;
    }else{
        while(currentL->next != NULL){
            currentL = currentL->next;
            len++;
        }
        newL->val = val;
        newL->next = NULL;
        newL->prev = currentL;
        currentL->next = newL;
        len++;
    }
    return len;
}

int pop(No **l){
    int retVal;
    No *currentL = *l;
    if(*l == NULL){
        return -1;
    }

    if(currentL->next == NULL){
        retVal = currentL->val;
        free(currentL);
        *l = NULL;
        return retVal;
    }
    while(currentL->next->next != NULL){
        currentL = currentL->next;
    }
    retVal = currentL->next->val;
    free(currentL->next);
    currentL->next = NULL;

    return retVal;
}

int unshift(No **l, int val){
    int len = 1;
    No *newL = malloc(sizeof(No));
    newL->val = val;

    if(*l == NULL){
        newL->next = NULL;
        newL->prev = NULL;
        *l = newL;
    }else{
        newL->next = *l;
        newL->prev = NULL;
        *l = newL;

        No *currentL = *l;
        while(currentL->next != NULL){
            currentL = currentL->next;
            len++;
        }
    }

    return len;
}
int shift(No **l){
    int retVal;
    if(*l == NULL){
        return -1;
    }
    No *nextL = *l;
    if(nextL->next == NULL){
        retVal = nextL->val;
        free(nextL);
        *l = NULL;
        return retVal;
    }
    nextL = nextL->next;
    *l = nextL;
    retVal = nextL->prev->val;
    free(nextL->prev);
    nextL->prev = NULL;

    return retVal;
}

int insert(No **l, int val, int index){
    return 0;
}
int removeL(No **l, int index){
    return 0;
}