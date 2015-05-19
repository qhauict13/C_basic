typedef struct node_s{
  void *value;
  struct node_s *next;
} stacknode;

stacknode* makeStackNode(void *e){
  stacknode *newNode;
  newNode = (stacknode*)malloc(sizeof(stacknode));
  if (newNode == NULL) return NULL;
  newNode -> value = e;
  newNode -> next = NULL;
  return newNode;
}

void push(stacknode **top, void *e){
  if(*top == NULL){
    (*top) = makeStackNode(e);
    return;
  }
  stacknode *newNode;
  newNode = makeStackNode(e);
  newNode -> next = *top;
  *top = newNode;
}

void pop(stacknode **top){
  if (*top == NULL){
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return;
  } else {
    stacknode *newNode = malloc(sizeof(stacknode));
    newNode = *top;
    *top = (*top)->next;
    free(newNode);
  }
}
//-------traverse a stack-----------
void printStack(stacknode *root){
  stacknode *temp = NULL;
  temp = root;
  while(temp != NULL){
    printf("%s\n",(char*)(root->value));
    temp = temp->next;
  }
  free(temp);
}
//-----reverse a stack---------------
void insertAtBottom(stacknode **root, void* e){
  void *temp;
  if((*root) == NULL) {
    push(root,e);
    return;
  }
  temp = (*root)->value;
  pop(root);
  insertAtBottom(root,e);

  push(root,temp);
}
void reverse(stacknode **root){
  void *temp;
  if((*root) == NULL){
    temp = (*root)->value;
    pop(root);
    reverse(root);
    insertAtBottom(root,temp);
  }
}
