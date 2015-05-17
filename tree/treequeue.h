typedef struct node_t{
  treenode *tree;
  struct node_t *next;
} treestack;

treestack* makeNode(treenode *e){
  treestack *newNode = malloc(sizeof(treestack));
  newNode->tree = e;
  newNode->next = NULL;
}

void dequeue(treestack **top){
  if(*top == NULL) return;
  else if ((*top)->next == NULL) *top = NULL;
  else {
  treestack *newNode = malloc(sizeof(treestack));
  treestack *temp = malloc(sizeof(treestack));
  temp = *top;
  while(temp->next!= NULL) temp = temp->next;
  newNode = *top;
  while(newNode->next != temp) newNode = newNode->next;
  newNode->next = NULL;
  free(temp);
  }
}

treenode *getvalue(treestack **top){
  if(*top == NULL) return;
  treestack *temp = malloc(sizeof(treestack));
  temp = *top;
  while(temp->next!= NULL) temp = temp->next;
  treenode *b = malloc(sizeof(treenode));
  b = temp->tree;
  free(temp);
  return b;
}

void printStack(treestack **top){
  if(*top == NULL) {
    printf("No data!\n"); return;
  } else {
    treestack *newNode = malloc(sizeof(treestack));
    newNode = *top;
    while(newNode!=NULL){
      printf("%s\n", newNode->tree->value);
      newNode = newNode->next;
    }
    free(newNode);
  }
}

void enqueue(treestack **top, treenode *e){
  if(*top == NULL) *top = makeNode(e);
  else{
  treestack *newNode = makeNode(e);
  newNode->next = *top;
  *top = newNode;
  }
}

int count(treestack **top){
  int i = 0;
  if(*top == NULL) return 0;
  else {
    treestack *newNode = malloc(sizeof(treestack));
    newNode = *top;
    while(newNode!=NULL){
      i++;
      newNode = newNode->next;
    }
    free(newNode);
  }
  return i;
}
