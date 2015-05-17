#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int datatype;
typedef struct node node;
struct node{
  datatype data;
  node* next;
};
node* prev(node *root,node* p){
  node* tmp = root;
  while(tmp != NULL){
    if(tmp->next == p) return tmp;
    tmp = tmp->next;
  }
  return NULL;
}
node* makeNewNode(datatype data){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
node* push(node *root,datatype newData){
  node* newNode;
  newNode = makeNewNode(newData);
  if(root == NULL){
    return newNode;
   
  }
  else{
    newNode->next = root;
    return newNode;
  }
}
node* pop(node *root)
{
	node *cur=root;
  if(root==NULL) return NULL;
  else 
    {
    	root=root->next;
      free(cur);
      return root;
    }
}
node *list_reverse(node *root)
{
  node *cur,*prev;
  cur=prev=NULL;
  while( root->next!=NULL)
    {
      cur=root;
      root=root->next;
      cur->next=prev;
      prev=cur; 
    }
   root->next=cur;
   cur=root;

}
void swap(char *a)
{
	int i,j;
	for(i=0;i<strlen(a)/2;i++)
	{
		j=a[i];
		a[i]=a[strlen(a)-1-i];
		a[strlen(a)-1-i]=j;
	}
}
node *travese(node *root)
{
	node *cur=root;
	if(cur==NULL) printf("No data.\n");
	else while(cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	return root;
}
node *clearnode(node *root)
{
	if(root==NULL) return NULL;
	node *cur = root->next;
	free(root);
	cur = clearnode(cur);
	
}
