#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include <ctype.h>
#define MAX 10000

typedef struct{
  int count;
  char word[30];
} wordCount ;

//-----------cut parts out of a string-------
char *partcut(char *ex){
  int i = 0, j = 0,k;
  if(strlen(ex) == 0) return NULL;
  while(isalpha(ex[i])) i++;
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
  //printf("%s - %s",a1,b1);
  return strcmp(a1,b1);
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
void writeToFile(bnode *root, FILE *file){
  if (root == NULL) return;
  char *e = ((wordCount*)(root->value))->word;
  int e1 = ((wordCount*)(root->value))->count;
  fprintf(file,"%s(%d)\n",e,e1);
  writeToFile(root->left,file);
  writeToFile(root->right,file);
}
void freeAll(bnode *root){
  if(root == NULL) return;
  freeAll(root->left);
  freeAll(root->right);
  free(root);
}

//----------main-------------
int main(){
  FILE *file, *file1;
  if((file = fopen("duplicate_words","r")) == NULL) {
    fprintf(stderr,"Cannot open file!\n");
    exit(1);
  }
  else if((file1 = fopen("wordcounting.txt","w")) == NULL){
    fprintf(stderr,"cannot create file!\n");
    exit(1);
  }
  int i = 0;
    bnode *root = NULL;
    char buff[MAX];
    char str[MAX];
    char *part = NULL;
    bnode *temp;
    while (fgets(buff,MAX,file) != NULL) {
      strcat(str,buff);
    }
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
      part = partcut(str);
      if(part == NULL) break;
      if(root == NULL){
        strcpy(b[i].word,part);
        b[i].count = 1;
        insertNode(&root,(void*)&b[i]);
      } else {
        strcpy(b[i].word,part);
        b[i].count = 1;
        temp = search(&root,(void*)&b[i]); //only search for word match

        if(temp == NULL) { //if no matching word is found
          insertNode(&root,(void*)&b[i]); //insert this word with count = 0
        }
        else{
          ((wordCount*)(temp->value))->count += 1;
          }
        }
      i++;

    }
    preorder(root);
    writeToFile(root,file1);
    free(b);
    freeAll(root);
  return 0;
}

