typedef char stringdatatype;
typedef struct stringnode stringnode;
struct stringnode{
  stringdatatype *data;
  stringnode* next;
};
stringnode* makeNewstringnode(stringdatatype *data){
  stringnode* newstringnode = (stringnode*)malloc(sizeof(stringnode));
  newstringnode->data = data;
  newstringnode->next = NULL;
  return newstringnode;
}
stringnode* stringpush(stringnode *root,stringdatatype *newData){
  stringnode* newstringnode;
  newstringnode = makeNewstringnode(newData);
  if(root == NULL){
    return newstringnode;
   
  }
  else{
    newstringnode->next = root;
    return newstringnode;
  }
}
stringnode* stringpop(stringnode *root)
{
	stringnode *cur=root;
  if(root==NULL) return NULL;
  else 
    {
    	root=root->next;
      free(cur);
      return root;
    }
}
stringnode *stringlist_reverse(stringnode *root)
{
  stringnode *cur,*prev;
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
stringnode *stringtravese(stringnode *root)
{
	stringnode *cur=root;
	printf("= ");
	if(cur==NULL) printf("-No data.\n");
	else while(cur!=NULL)
	{
		printf("%s ",cur->data);
		cur = cur->next;
	}
	printf("\n");
	return root;
}
stringnode *clearstringnode(stringnode *root)
{
	if(root==NULL) return NULL;
	stringnode *cur = root->next;
	free(root);
	cur = clearstringnode(cur);
	
}
