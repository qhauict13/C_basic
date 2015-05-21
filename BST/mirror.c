#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "BST.h"
#define MAX 1000
//----cut a string into parts-----------
char *partcut(char *ex)
{
  int i=0,j,k;
  if(strlen(ex)==0) return NULL;
  while( ex[i]!=' ' && i<strlen(ex) && ex[i]!='\n')  i++;
  char* b = (char*)malloc(i*sizeof(char));
  for(j=0;j<i;j++)
    b[j]=ex[j];
  b[i]='\0';
  for(k=0;k<=i;k++)
    for(j=0;j<strlen(ex);j++) ex[j]=ex[j+1];
  return b;
}
//--------compare 2 values-----------
int cmp(const void *a, const void *b){
  return 1;
}
//----pretty transform an expression---------
char *transform(char *a)
{
  int i,j,k;
  for (i=0;i<strlen(a);i++)
    if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='%'||a[i]=='('||a[i]==')')
      {
        if(a[i-1]!= ' ')
          {
            k=strlen(a);a[k]=' ';a[k+1]='\0'; k=strlen(a);
            for(j=k-1;j>i;j--) a[j]=a[j-1];  a[i]=' ';
            i++;
          }

        if(a[i+1]!= ' ')
          {
            k=strlen(a);a[k]=' ';a[k+1]='\0'; k=strlen(a);
            for(j=k-1;j>i+1;j--) a[j]=a[j-1];  a[i+1]=' ';
          }
      }

  while(a[0]==' ') for(i=0;i<strlen(a);i++) a[i]=a[i+1];
  while(a[strlen(a)-1]==' ') a[strlen(a)-1]='\0';
  for(i=1;i<strlen(a)-1;i++)
    {
      if(a[i]==' '&&a[i+1]==' ')
        {
          for(j=i+1;j<strlen(a);j++)
            a[j]=a[j+1];
          i--;
        }
    }
  k=strlen(a);a[k]=' ';a[k+1]='\0';
  return a;
}
//-------is a part on operand--------------
int isOperand(char *a)
{
  if(!strcmp(a,"*")) return 1;
  if(!strcmp(a,"/")) return 1;
  if(!strcmp(a,"+")) return 1;
  if(!strcmp(a,"-")) return 1;
  if(!strcmp(a,"^")) return 1;
  return 0;

}
int isOperandCheck(char a){
  if(a == '+') return 1;
  if(a == '-') return 1;
  if(a == '/') return 1;
  if(a == '*') return 1;
  if(a == '^') return 1;
  return 0;
}
int prec(char *e) {
  int pre = 0;
  if (!strcmp(e,"*") || !strcmp(e,"/"))
    pre = 2;
  else if (!strcmp(e,"-") || !strcmp(e,"+"))
    pre = 1;
  else if(!strcmp(e,"^"))
    pre = 3;
  else pre = -1;
  return pre;
}
//------check validity of an expression-----------
int check(char *a){
  int i = 0;
  if (isOperandCheck(a[strlen(a)-2])) return 0;
  if (isOperandCheck(a[0])) return 0;
  for (i=0;i<strlen(a)-2;i++) if(a[i]=='('&&a[i+2]==')') return 0;
  return 1;
}
//-------check if a string is numeric----------
int isNumeric (const char *s)
{
  if (s == NULL || *s == '\0' || isspace(*s))
    return 0;
  char *p;
  strtod(s, &p);
  return *p == '\0';
}
//------the fun part-----------------
stacknode *infix2postfix(char *ex){
  int i,k;
  char *part = NULL;
  stacknode *output = NULL, *temp = NULL;
  stacknode *a;
  while(ex!=NULL){
    a = NULL;
    part = partcut(ex);
    if(part==NULL) break;
    if (isNumeric(part)) push(&output,(void*)part);

    else if (!strcmp(part,"(")) {
      push(&temp,(void*)part);
    }

    else if (!strcmp(part,")")){
      while(temp != NULL && strcmp((char*)(temp->value),"(")) {
        a = temp;
        push(&output,a->value);
        pop(&temp);
      }
      pop(&temp);
    }
    else if (isOperand(part)){
      while(temp != NULL && prec(part) <= prec((char*)(temp->value))){
        a = temp;
        push(&output,a->value);
        pop(&temp);
      }
      push(&temp,(void*)part);
      }
  }
  a = NULL;
  while(temp!=NULL){
    a = temp;
    push(&output,a->value);
    pop(&temp);
  }
  reverse(&output);
  return output;
}

bnode* maketree(bnode **tree, stacknode *input){
  char *part=NULL;
  stacknode *output=NULL;
  stacknode *part1 = malloc(sizeof(stacknode));
  stacknode *part2 = malloc(sizeof(stacknode));
  int n = 0;
  while(1){
    if(input == NULL) break;
    part=(char*)(input->value);
    pop(&input);
    //---------------------------------------------
    if(isNumeric(part)) push(&output,(void*)part);
    else if(isOperand(part)&&n==0){
      part1->value = output->value;
      pop(&output);
      part2->value = output->value;
      pop(&output);

      bnode *left = makeTreeNode(part1->value);
      bnode *right = makeTreeNode(part2->value);
      *tree = makeTreeNode((void*)part);
      *tree = createFromSub(tree,left,right);
      n++;
    }
    else if(isOperand(part)&&(n!=0)){
      part1->value = output->value;
      pop(&output);
      bnode *left = makeTreeNode(part1->value);
      bnode *newtree = makeTreeNode((void*)part);
      newtree = createFromSub(&newtree,(*tree),left);
      *tree = newtree;
    }
  }
  return *tree;
}
//--------------mirror a tree-------------
  void mirror(bnode *root){
  if(root == NULL) return;
  else {
  bnode *temp;
  mirror(root->left);
  mirror(root->right);

  temp = root->left;
  root->left = root->right;
  root->right = temp;
  }
}
//-----------print a node---------------
void printNode(bnode **node){
  if(*node == NULL) {
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  printf("%s\n",(char*)((*node)->value));
}
void preorder(bnode *root){
  if(root == NULL) return;
  printNode(&root);
  preorder(root->left);
  preorder(root->right);
}

int main(int argc, char *argv[])
{
  int option = 0;
  stacknode *output = NULL;
  bnode *root = NULL;
  char inputString[MAX];
  char *ex;
  while(1){
    printf("\nInput the expression: ");
    scanf(" %[^\n]",inputString);
    ex = transform(inputString);
    printf("expression = %s\n",ex);
    if(check(ex)){
      output = infix2postfix(ex);
      root = maketree(&root,output);
      printf("Preorder the tree before reversing:\n");
      preorder(root);
      mirror(root);
      printf("Preorder the tree after reversing:\n");
      preorder(root);
    }
    else printf("Math error!\n");
    printf("Do you want to continue? (1=yes): ");
    scanf("%d",&option);
    if (option != 1) break;
  }
  return 0;
}
