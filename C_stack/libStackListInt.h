typedef struct node_s{
	int value;
	struct node_s *next;
} node;

typedef struct node_c{
	char *value;
	struct node_c *next;
} node_c;

node* makeNode(int e){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  if (newNode == NULL) printf("memory allocation failed!\n");
  newNode -> value = e;
  newNode -> next = NULL;
  return newNode;
}

node_c *makeNodeChar(char *e){
	node_c* newNode;
	newNode = (node_c*)malloc(sizeof(node_c));
	if (newNode == NULL) printf("memory allocation failed!\n");
	newNode -> value = e;
	newNode -> next = NULL;
	return newNode;
}

void push(node **topList, int e){
  node *newNode;
  newNode = makeNode(e);
  newNode -> next = *topList;
  *topList = newNode;
}

void pushChar(node_c **topList, char *e){
	node_c *newNode;
	newNode = makeNodeChar(e);
	newNode -> next = *topList;
	*topList = newNode;
}

int pop(node **topList){
	if (*topList == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		int tempValue;
		tempValue = (*topList)->value;

		node *newNode;
		newNode = (node*)malloc(sizeof(node));
		newNode = (*topList);
		*topList = (*topList)->next;
		free(newNode);
		return tempValue;
	}
}

char* popChar(node_c **topList){
	if (*topList == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		char *temp;
		temp = (*topList)->value;
		
		node_c *newNode;
		newNode = (node_c*)malloc(sizeof(node_c));
		newNode = (*topList);
		*topList = (*topList)->next;
		free(newNode);
		return temp;
	}
}

void printStack(node **topList){
	if (*topList == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		node *newNode;
		newNode = (node*)malloc(sizeof(node));
		newNode = *topList;
		while(newNode != NULL){
			printf("%d   ", newNode->value);
			newNode = newNode->next;
		}
		free(newNode);
	}
}

void printStackChar(node_c **topList){
	if (*topList == NULL){
		printf("Stack empty!\n");
		return;
	} else {
		node_c *newNode;
		newNode = (node_c*)malloc(sizeof(node_c));
		newNode = *topList;
		while(newNode != NULL){
			printf("%s   ", newNode->value);
			newNode = newNode->next;
		}
		free(newNode);
	}
}

void freeAll(node **rootList){
  node *newNode = malloc(sizeof(node));
  for (newNode = *rootList; newNode != NULL; newNode = newNode->next){
    node* temp = malloc(sizeof(node));
    temp = newNode;
    newNode = newNode->next;
    free(temp);
  }
}