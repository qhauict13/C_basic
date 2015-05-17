typedef struct node_s{
  void *value;
  struct node_s *next;
} node;

node* makeNode(void *e){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  if (newNode == NULL) return NULL;
  newNode -> value = e;
  newNode -> next = NULL;
  return newNode;
}

void push(node **top, void *e){
  node *newNode;
  newNode = makeNode(e);
  newNode -> next = *top;
  *top = newNode;
}

void pop(node **top){
	if (*top == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		node *newNode = malloc(sizeof(node));
		newNode = (*top);
		*top = (*top)->next;
		free(newNode);
	}
}

void freeAll(node **top){
  node *newNode = malloc(sizeof(node));
  for (newNode = *top; newNode != NULL; newNode = newNode->next){
    node* temp = malloc(sizeof(node));
    temp = newNode;
    newNode = newNode->next;
    free(temp);
  }
}
