#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#define MAX 1000
void traverse_stack(stacknode **top){
  if(*top == NULL){
    printf("Stack empty!\n");
    return;
  }
  int a[MAX];
  int i = 0;
  stacknode *newNode = *top;
  while(newNode!=NULL){
    printf("%d\n", *(int*)newNode->value);
    newNode=newNode->next;
  }
  free(newNode);
}

int main(int argc, char *argv[])
{
  FILE *file;
  if ((file = fopen("testNum.txt","r")) == NULL) printf("Cannot open file!\n");
  else {
    char buff[MAX];
    int n = 0,i = 0;
    while(fgets(buff,MAX,file) != NULL) n++;
    fseek(file,0,SEEK_SET);
    stacknode *top = NULL;
    int k[MAX];
    while (i < n){
      fscanf(file,"%d", &k[i]);
      printf("%d\n",k[i]);
      top = push(top,(void*)&k[i]);
      i++;
    }
    traverse_stack(&top);
  }
  return 0;
}
