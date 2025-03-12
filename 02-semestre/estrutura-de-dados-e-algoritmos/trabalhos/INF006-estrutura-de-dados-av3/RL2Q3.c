//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
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

void removeNo(No **root, int val);

No *searchNo(No *root, int val){
  No *current = root;
  while(current != NULL){
    if(val < current->val){
      current = current->left;
    }else if(val > current->val){
      current = current->right;
    }else if(val == current->val){
      return current;
    }
  }
  return NULL;
}

int insertNo(No **root, int val){
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

void updateHeight(No *parent){ // update heights of subTree based on the height of the parent
  if(parent != NULL){
    No *current = parent;
    while(current != NULL){
      if(current->left != NULL){
        current->left->height = current->height + 1;
        updateHeight(current->left);
      }
      if(current->right != NULL){
        current->right->height = current->height + 1;
        updateHeight(current->right);
      }
      break;
    }
  }
}

No *successorNode(No *leaf){
  No *current = leaf->right;
  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

void removeLeaf(No **root,No *leaf){
  if(leaf->parent != NULL){
    if(leaf->parent->left == leaf){
      leaf->parent->left = NULL;
    }else{
      leaf->parent->right = NULL;
    }
  }else{//root will be removed
    *root = NULL;
  }
  free(leaf);
}

void removeWOnlyChild(No **root, No *leaf){
  if(leaf->parent == NULL){//root
    if(leaf->left != NULL){
      leaf->left->height = 0;
      *root = leaf->left;
      leaf->left->parent = NULL;
    }else{
      leaf->right->height = 0;
      *root = leaf->right;
      leaf->right->parent = NULL;
    }
    updateHeight(*root);
  }else{
    if(leaf->parent->left == leaf){
      if(leaf->left != NULL){
        leaf->parent->left = leaf->left;
        leaf->left->parent = leaf->parent;
      }else{
        leaf->parent->left = leaf->right;
        leaf->right->parent = leaf->parent;
      }
    }else{
      if(leaf->left != NULL){
        leaf->parent->right = leaf->left;
        leaf->left->parent = leaf->parent;
      }else{
        leaf->parent->right = leaf->right;
        leaf->right->parent = leaf->parent;
      }
    }
  updateHeight(leaf->parent);
  }
  free(leaf);
}

void removeWTwoChildren(No **root, No *leaf){
  No *successor = successorNode(leaf);
  leaf->val = successor->val;
  updateHeight(leaf);
  removeNo(&successor, successor->val);
}

void removeNo(No **root, int val){
  No *current = searchNo(*root, val);
  if(current == NULL){
    insertNo(root, val);
    return;
  }

  if(current->left == NULL && current->right == NULL){ //No folha
    removeLeaf(root, current);
  }else if(current->left == NULL || current->right == NULL) {//No com apenas um filho
    removeWOnlyChild(root, current);
  }else if(current->left != NULL && current->right != NULL){ //No com dois filhos
    removeWTwoChildren(root, current);
  }
}

void writeInOrder(No *root, char *text, int *el){
  if(root){
    writeInOrder(root->left, text, el);
    if(*el == 0){
      sprintf(text,"%s%d (%d)", text, root->val, root->height);
    }else{
      sprintf(text,"%s %d (%d)", text, root->val, root->height);
    }
    *el = *el + 1;
    writeInOrder(root->right, text, el);
  }
}


int main(){
  FILE *fp_in = fopen("L2Q3.in", "r");
  FILE *fp_out = fopen("L2Q3.out", "w");
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
      if(slice[0] == 'a'){
        slice = strtok(NULL, space);
        int val = atoi(slice);
        insertNo(&root, val);
      }else if(slice[0] == 'r'){
        slice = strtok(NULL, space);
        int val = atoi(slice);
        removeNo(&root, val);
      }

      slice = strtok(NULL, space);
    }

    writeInOrder(root, text, &el);
    
    fputs(text, fp_out);
    lineCount++;
  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}