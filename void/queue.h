typedef struct node_q{
  void *value;
  struct node_q *next;
} queuenode;

queuenode *makeNode(void *e){
  queuenode *newNode = malloc(sizeof(queuenode));
  if(newNode == NULL) return NULL;
  newNode->value = e;
  newNode->next = NULL;
  return newNode;
}

queuenode *enqueue(queuenode *top, void* e){
  if (top == NULL) top = makeNode(e);
  else {
    node *newNode = makeNode(e);
    newNode->next = top;
    top = newNode;
  }
  return top;
}

queuenode *dequeue(queuenode *top, void *e){
  if(top == NULL) return NULL;
  else if(top->next == NULL)
}
