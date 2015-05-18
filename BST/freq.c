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
  if(node == NULL) {
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
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
  int i = 0;
    bnode *root = NULL;
    char str[MAX];
    char *part = NULL;
    bnode *temp;
    if(fgets(str,MAX,file) != NULL) printf("\n");
    char ex[MAX];
    strcpy(ex,str);
    while(ex != NULL){
      part = partcut(ex);
      if(part == NULL) break;
      i++;
    }

    wordCount *b = malloc(i*sizeof(wordCount));
    part = NULL; i = 0;

    while(str != NULL){
      if(root == NULL){
        part = partcut(str);
        if(part == NULL) break;
        strcpy(b[i].word,part);
        b[i].count = 0;
        insertNode(&root,(void*)&b[i]);
        printNode(root);
      } else {
        part = partcut(str);
        if(part == NULL) break;

        strcpy(b[i].word,part);
        b[i].count = 0;
        temp = search(&root,(void*)&b[i]);

        if(temp == NULL) {
          insertNode(&root,(void*)&b[i]);

        }
        else{
          b[i].count = ((wordCount*)(temp->value))->count;
          //printf("%s - %d\n",b[i].word,b[i].count);
          deleteNode(&root,(void*)(b[i].word));
          b[i].count += 1;
          insertNode(&root,(void*)&b[i]);
          }
          }
      i++;
    }
    printf("Inorder traversal: \n");
    free(b);
    inorder(root);
    freeAll(root);
  return 0;
}

