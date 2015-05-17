#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#define MAX 1000

typedef struct{
  char word[30];
  char def[100];
} dict;

int cmp(const void *a,const void *b){
  char* a1 = ((dict*)a)->word;
  char* b1 = ((dict*)b)->word;
  return strcmp(a1,b1);
}

void insertNode(bnode **root, void *e){
  int c;
  if(e == NULL) return;
  if((*root) == NULL){
    *root = makeTreeNode(e);
    return;
  }
  else {
    c = cmp(e,(*root)->value);
    if(c < 0) insertNode(&((*root)->left),e);
    if(c > 0) insertNode(&((*root)->right),e);
  }
}

bnode *search(bnode* root, void *e){
  if(root == NULL) return NULL;
  int c;
  c = cmp(e,root->value);
  if(c == 0) return root;
  if(c < 0) root->left = search(root->left,e);
  if(c > 0) root->right = search(root->right,e);
}

void printNode(bnode* node){
  if(node == NULL) return;
  char *e1 = ((dict*)(node->value))->word;
  char *e2 = ((dict*)(node->value))->def;
  printf("%s-%s\n", e1, e2);
}
void preorder(bnode *root){
  if(root == NULL) return;
  printNode(root);
  preorder(root->left);
  preorder(root->right);
}
void inorder(bnode *root){
  if(root == NULL) return;
  inorder(root->left);
  printNode(root);
  inorder(root->right);
}
void postorder(bnode *root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printNode(root);
}
void freeAll(bnode *root){
  if(root == NULL) return;
  freeAll(root->left);
  freeAll(root->right);
  free(root);
}
int getMenu(){
  int choice;
  printf("\n1.Search\n");
  printf("2.Add words\n");
  printf("3.Delete words\n");
  printf("4.Write data into file\n");
  printf("5.Print out tree (preorder)\n");
  printf("6.Print out tree (inorder)\n");
  printf("7.Print out tree (postorder)\n");
  printf("0.Exit and free all\n");
  printf("Your choice: "); scanf("%d", &choice);
  return choice;
}

int main(){
  FILE *file;
  if ((file = fopen("dictionary","r")) == NULL) printf("Cannot open file!\n");
  else {
    bnode* root = NULL;
     char buff[MAX];
    int i = 0, size = 0;
    dict *array, tempDict;

    char str[MAX];
    char str2[MAX];
    bnode *temp;
    while(fgets(buff,MAX,file) != NULL){
      size++;
    }
    rewind(file);
    array = (dict*)malloc(size*sizeof(dict));

    for(i = 0; i < size; i++){
      fscanf(file,"%[^-]-%[^-\n]\n",array[i].word,array[i].def);
      insertNode(&root,(void*)&array[i]);
    }
    for(;;){
      switch(getMenu()){
      case 1: printf("Enter search term: ");
        scanf(" %[^\n]", str);
        while ( getchar() != '\n' );

        temp = search(root,(void*)str);
        if (temp == NULL) printf("Word cannot be found!\n");
        else printf("Definition: %s\n",((dict*)(temp->value))->def);
        break;
      case 2: printf("Enter a word: ");
        scanf(" %[^\n]",str);
        while ( getchar() != '\n' );
        printf("\nEnter its definition: ");
        scanf(" %[^\n]",str2);
        while ( getchar() != '\n' );
        strcpy(tempDict.word,str);
        strcpy(tempDict.def,str2);
        printf("\nYou have inserted: %s-%s",tempDict.word,tempDict.def);
        insertNode(&root,(void*)&tempDict);
        break;
      case 3:  printf("Enter a word: ");
        scanf(" %[^\n]",str);
        while ( getchar() != '\n' );
        temp = search(root,(void*)str);
        if (temp == NULL) printf("Word cannot be found!\n");
        else {
          deleteNode(&root,temp);
        }
        break;
      case 5: preorder(root); break;
      case 6: inorder(root); break;
      case 7: postorder(root); break;
      case 0: freeAll(root);
        return 0;
      }
    }
  }
  return 0;
}
