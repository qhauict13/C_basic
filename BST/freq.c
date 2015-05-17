#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#define MAX 1000

typedef struct{
  int count;
  char word[30];
} wordCount ;
//-----------cut parts out of a string-------
char *partcut(char *ex){
  int i = 0, j = 0,k;
  if(strlen(ex) == 0) return NULL;
  while(ex[i]!=' '&&i<strlen(ex)&&ex[i]!='\n') i++;
  char *b = (char*)malloc(i*sizeof(char));
  for (j = 0; j < i; j++) {
    b[j]=ex[j];
  }
  b[i]='\0';
  for(k = 0;k<=i;k++){
    for(j=0;j<strlen(ex);j++)
      ex[j]=ex[j+1];
  }
  return b;
}
//--------compare 2 values-----------
int cmp(const void *a, const void *b){
  char *a1 = ((wordCount*)a)->word;
  char *b1 = ((wordCount*)b)->word;
  return strcmp(a1,b1);
}

//-------insert node (have value)---------------
void insertNode(bnode **root, void *e){
  int c;
  if(e == NULL) {
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  if((*root) == NULL){
    *root = makeTreeNode(e);
    return;
  } else {
    c = cmp(e,(*root)->value);
    if (c < 0) insertNode(&((*root)->left),e);
    if (c > 0) insertNode(&((*root)->right),e);
  }
}

//---------print nodes and tree in various ways----------
void printNode(bnode *node){
  if(node == NULL) return;
  char *e = ((wordCount*)(node->value))->word;
  int e1 = ((wordCount*)(node->value))->count;
  printf("%s(%d)\n",e,e1);
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
//----------main-------------
int main(){
  FILE *file;
  if((file = fopen("duplicate_words","r")) == NULL) {
    fprintf(stderr,"Cannot open file!\n");
    exit(1);
  }
    bnode *root = NULL;
    char str[MAX];
    char *part = NULL;
    bnode *temp;
    wordCount a,b;
    if(fgets(str,MAX,file) != NULL) printf("\n");

    while(str != NULL){
      if(root == NULL){
        part = partcut(str);
        if(part == NULL) break;
        strcpy(a.word,part);
        a.count = 0;
        insertNode(&root,(void*)&a);
      } else {
        part = partcut(str);
        if(part == NULL) break; //

        strcpy(a.word,part);
        a.count = 0;
        printNode(root);
        temp = search(root,(void*)&a);/*
        if(temp == NULL) {
          insertNode(&root,(void*)&a);
        }
        else{
          strcpy(b.word,((wordCount*)(temp->value))->word);
          b.count = ((wordCount*)(temp->value))->count;
          //printf("%s(%d)\n",b.word,b.count);
          deleteNode(&root,(void*)(b.word));
          b.count += 1;
          insertNode(&root,(void*)&b);
          }*/
      }
    }
    printf("Inorder traversal: \n");
    //inorder(root);
    freeAll(root);
  return 0;
}

