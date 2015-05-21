#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#define MAX 1000

typedef struct {
  char name[50];
  char phone[15];
  double grade;
} student;

//--------print a tree node-----------
void printTreeNode(bnode *node){
  if(node == NULL){
    fprintf(stderr,"ERROR in file %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  char *a = ((student*)(node->value))->name;
  char *b = ((student*)(node->value))->phone;
  double c = ((student*)(node->value))->grade;
  printf("%s - %s - %.1lf\n",a,b,c);
}
void inorder(bnode *root){
  if(root == NULL) return;
  inorder(root->left);
  printTreeNode(root);
  inorder(root->right);
}
//--------compare 2 values-----------
int cmp(const void *a, const void *b){
  double a1 = ((student*)a)->grade;
  double b1 = ((student*)b)->grade;
  int c;
  if(a1 > b1) c = 1;
  else if(a1 == b1) c = 0;
  else if(a1 < b1) c = -1;
  return c;
}
//-------compare func w/ value as parameter---------
int cmp2(const void *a, const void *b){
  double a1 = *((double*)a);
  double b1 = ((student*)b)->grade;
  int c;
  if(a1 > b1) c = 1;
  else if(a1 == b1) c = 0;
  else if(a1 < b1) c = -1;
  return c;
}
//-------grade is lower than x------------
void lowerThan(bnode **root, void *e, int *i){
  if(e == NULL){
    fprintf(stderr,"ERROR in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  if(*root == NULL) return;
  int c = cmp2(e,(*root)->value);
  if(c > 0){
    printTreeNode(*root);
    (*i)++;
  }
  //else if (c < 0) printf("\n");
  lowerThan(&((*root)->left),e,i);
  lowerThan(&((*root)->right),e,i);
}
//---------grade is higher than x-----------
void higherThan(bnode **root, void *e, int *i){
  if(e == NULL){
    fprintf(stderr,"ERROR in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  if(*root == NULL) return;
  int c = cmp2(e,(*root)->value);

  if(c < 0){
    printTreeNode(*root);
    (*i)++;
  }
  //else if (c > 0) printf("\n");
  higherThan(&((*root)->left),e,i);
  higherThan(&((*root)->right),e,i);
}
//----------make a menu--------------------
int getMenu(){
  int option;
  printf("1.Print out the list of students\n");
  printf("2.Find students w/ lower grade\n");
  printf("3.Find students w/ higher grade\n");
  printf("0.Exit\n");
  printf("Your choice: "); scanf("%d",&option);
  return option;
}
//----------MAIN-------------------------
int main(){
  FILE *file;
  bnode *root = NULL;
  int i = 0, size = 0;
  double value;
  int count = 0;
  if((file = fopen("students","r")) == NULL){
    fprintf(stderr,"Cannot open file!\n");
    exit(1);
  }
  char buff[MAX];
  while(fgets(buff,MAX,file) != NULL) size++;
  fseek(file,0,SEEK_SET);
  student *array = malloc(sizeof(student)*size);
  while(i<size){
    fscanf(file,"%[^-]-%[^-]-%lf\n",array[i].name,array[i].phone,&array[i].grade);
    insertNode(&root, (void*)&array[i]);
    i++;
  }
  for(;;){
    switch(getMenu()){
    case 1: printf("\nList of students: \n");
      inorder(root);
      printf("\n");
      break;
    case 2: printf("Input a grade value to compare: ");
      scanf("%lf",&value);
      printf("\n");
      printf("Students that have grades lower than %.1lf:\n",value);
      lowerThan(&root,(void*)&value,&count);
      printf("Number of them: %d\n\n",count);
      count = 0;
      break;
    case 3: printf("Input a grade value to compare: ");
      scanf("%lf",&value);
      printf("\n");
      printf("Students that have grades higher than %.1lf:\n",value);
      higherThan(&root,(void*)&value,&count);
      printf("Number of them: %d\n\n",count);
      count = 0;
      break;
    case 0: return 0;
    default: printf("Enter an option above!\n");
    }
  }
return 0;
}
