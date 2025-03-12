//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  int val;
  int height;
  struct no *left;
  struct no *right;
  struct no *parent;
} No;

int insert(No **root, int val){
  No *new = (No*)malloc(sizeof(No));
  int height = 0;
  new->val = val;
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
      }else{
        current = current->right;
        height++;
        if(current == NULL){
          parent->right = new;
          new->parent = parent;
          new->height = height;
          return new->height;
        }
      }
    }
  }

  return 0;
}

No *maxNode(No *root){
  No *current = root;
  while(current->right != NULL){
    current = current->right;
  }
  return current;
}


int main(){
  FILE *fp_in = fopen("L2Q1.in", "r");
  FILE *fp_out = fopen("L2Q1.out", "w");
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

      sprintf(text, "%s%d ", text, height);
      slice = strtok(NULL, space);
    }

    No *max = maxNode(root);

    sprintf(text, "%smax %d alt %d pred ", text, max->val, max->height);

    if(max->parent == NULL){
      sprintf(text, "%sNaN", text);
    }else{
      sprintf(text, "%s%d", text, max->parent->val);
    }
    
    fputs(text, fp_out);
    lineCount++;
  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}