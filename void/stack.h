typedef struct node_s{
  void *value;
  struct node_s *next;
} stacknode;

stacknode* makeNode(void *e){
  stacknode *newNode;
  newNode = (stacknode*)malloc(sizeof(stacknode));
  if (newNode == NULL) return NULL;
  newNode -> value = e;
  newNode -> next = NULL;
  return newNode;
}

stacknode* push(stacknode *top, void *e){
  stacknode *newNode;
  newNode = makeNode(e);
  newNode -> next = top;
  top = newNode;
  return top;
}

void *pop(stacknode **top){
	if (top == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		stacknode *newNode = malloc(sizeof(stacknode));
		newNode = (*top);
		*top = (*top)->next;
		free(newNode);
	}
}
