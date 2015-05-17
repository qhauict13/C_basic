#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"tree.h"
#include"treequeue.h"
#define MAX 1000
#define NUM 16

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

treenode* maketree(char *ex){
  srand(time(NULL));
  int r;
  int i = 0;

  char *part = NULL;
  treenode *tree1, *tree2;

  treestack *root = NULL;

  while(ex != NULL){
    part = partcut(ex);
    if(part == NULL) break;
    treenode *newNode = makeTreeNode(part);
    enqueue(&root,newNode);
  }
  printf("Matches: \n");
  while(count(&root) != 1){
    tree1 = getvalue(&root);
    dequeue(&root);
    tree2 = getvalue(&root);
    dequeue(&root);

    printf("%s vs %s",tree1->value,tree2->value);
    r=rand() % 2;
    if (r == 0){
      treenode *newNode = malloc(sizeof(treenode));
      newNode = tree1;
      newNode = createFromSub(newNode,tree1,tree2);
      enqueue(&root,newNode);
      printf("Winner: %s\n",newNode->value);
    }
    else if(r == 1){
      treenode *newNode = malloc(sizeof(treenode));
      newNode = tree2;
      newNode = createFromSub(newNode,tree1,tree2);
      enqueue(&root,newNode);
      printf("\tWinner: %s\n",newNode->value);
    }
    }
  return root->tree;
}

int main(int argc, char *argv[]){
  FILE *file;
  treenode *tree = NULL;
  if ((file = fopen("USopen","r")) == NULL) printf("Cannot open file!\n");
  else {
    char str[MAX];
    if(fgets(str,MAX,file) != NULL) printf("\n");
    tree = maketree(str);
    printf("\nFinalist: %s\n",tree->value);
  }
  fclose(file);
  return 0;
}
