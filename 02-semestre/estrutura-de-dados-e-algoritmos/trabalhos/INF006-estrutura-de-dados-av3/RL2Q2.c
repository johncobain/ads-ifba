//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  int val;
  int height;
  int sum;
  struct no *left;
  struct no *right;
  struct no *parent;
} No;

int sumNodes(No *root){
  if(root != NULL){
    return root->val + sumNodes(root->left) + sumNodes(root->right);
  }else{
    return 0;
  }
}

int insert(No **root, int val){
  // NO DUPLICATES
  No *new = (No*)malloc(sizeof(No));
  int height = 0;
  new->val = val;
  new->sum = 0;
  new->left = NULL;
  new->right = NULL;
  new->parent = NULL;
  new->height = height;

  if(*root == NULL){
    *root = new;
  }else{
    No *current = *root;
    No *parent = NULL;
    while(1){
      parent = current;
      if(val < current->val){
        current = current->left;
        height++;
        if(current == NULL){
          parent->left = new;
          new->parent = parent;
          new->height = height;
          return new->height;
        }
      }else if(val > current->val){
        current = current->right;
        height++;
        if(current == NULL){
          parent->right = new;
          new->parent = parent;
          new->height = height;
          return new->height;
        }
      }else{
        free(new);
        return -1;
      }
    }
  }

  return 0;
}

void calculateDiferences(No *root){ // node->sum = sum(node->right) - sum(node->left)
  if(root != NULL){
    root->sum = sumNodes(root->right) - sumNodes(root->left);
    calculateDiferences(root->left);
    calculateDiferences(root->right);
  }
}

void writeInOrder(No *root, char *text, int *el){
  if(root){
    writeInOrder(root->left, text, el);
    if(*el == 0){
      sprintf(text,"%s%d (%d)", text, root->val, root->sum);
    }else{
      sprintf(text,"%s %d (%d)", text, root->val, root->sum);
    }
    *el = *el + 1;
    writeInOrder(root->right, text, el);
  }
}

int main(){
  FILE *fp_in = fopen("L2Q2.in", "r");
  FILE *fp_out = fopen("L2Q2.out", "w");
  char line[1000];
  char space[] = " ";
  int lineCount = 0;

  if(fp_in == NULL || fp_out == NULL){
    printf("Arquivos nao podem ser abertos.");
    return EXIT_FAILURE;
  }

  while(fgets(line, sizeof(line), fp_in) != NULL){
    No *root = NULL;
    char text[1000];
    int el = 0;

    line[strcspn(line, "\n")] = '\0'; // Remove o \n da linha lida
    line[strcspn(line, "\r")] = '\0'; // Remove o \r da linha lida

    char *slice = strtok(line, space);

    if(lineCount != 0){
      sprintf(text, "\n");
    }else{
      sprintf(text, "");
    }

    while(slice != NULL){
      int val = atoi(slice);
      int height = insert(&root, val);
      slice = strtok(NULL, space);
    }

    calculateDiferences(root);
    writeInOrder(root, text, &el);
    
    fputs(text, fp_out);
    lineCount++;
  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}