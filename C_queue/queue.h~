#define MAX_MEMORY 10000
#define MAX_PROG 5


typedef struct node_s{
  int id;
  int memory;
  struct node_s *next;
} node;

node* makeNode(int newID, int mem){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  if(newNode == NULL) {
    printf("cannot create new node!\n");
    return;
  }
  newNode->id = newID;
  newNode->memory = mem;
  newNode->next = NULL;
  return newNode;
}

void enqueue(node **top, int newID, int mem){
  if (*top == NULL) *top = makeNode(newID,mem);
  else {
    node *newNode;
    newNode = makeNode(newID,mem);
    newNode->next = *top;
    *top = newNode;
  }
}

void dequeue(node **top, int *a, int *b){
  if (*top == NULL){
    printf("queue is empty!\n");
    return;
  } else if (((*top))->next == NULL) {
    *a = (*top)->id; *b = (*top)->memory;
    *top = NULL;
  } else {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp = *top;
    while(temp->next != NULL){
      temp = temp->next;
    }
    newNode = *top;
    while(newNode->next != temp){
      newNode = newNode->next;
    }
    *a = temp->id; *b = temp->memory;
    newNode->next = NULL;
    free(temp);
  }
}

void dequeue_run(node **top){
  if (*top == NULL){
    printf("queue is empty!\n");
    return;
  } else if (((*top))->next == NULL) {
    *top = NULL;
  } else {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp = *top;
    while(temp->next != NULL){
      temp = temp->next;
    }
    newNode = *top;
    while(newNode->next != temp){
      newNode = newNode->next;
    }
    newNode->next = NULL;
    free(temp);
  }
}
int countQueue(node **top){
  int count = 0;
  if (*top == NULL) {
    printf("No program in this queue!\n");
    return 0;
  } else {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode = *top;
    do{
      count++;
      newNode = newNode->next;
    } while(newNode != NULL);
    free(newNode);
  }
  return count;
}

int get_memory(node **top){
  int total = 0;
  if (*top == NULL) {
    printf("No program in this queue!\n");
    return 0;
  } else {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode = *top;
    do{
      total += newNode->memory;
      newNode = newNode->next;
    } while(newNode != NULL);
    free(newNode);
  }
  return total;
}
int scan(node **top, int n){
  if (*top == NULL) return 0;
  node *temp = malloc(sizeof(node));
  temp = *top;
  do {
    if(temp->id == n) return 1;
    temp = temp->next;
  } while(temp != NULL);
  return 0;
}

void create_prog(node **running, node **waiting){
  int newID, newMem;
  int runningMem = get_memory(&(*running));
  printf("Used memory: %d\n", runningMem);
  do {
    printf("Enter new program's id: ");
    scanf("%d", &newID);
    if (scan(&(*running),newID) || scan(&(*waiting),newID)) printf("Used id!\n");
  } while (scan(&(*running),newID) || scan(&(*waiting),newID));
  printf("\nEnter new program's memory: ");
  scanf("%d", &newMem);

  if(newMem + runningMem > MAX_MEMORY){
    printf("The memory is full, opened program will be in the waitlist\n");
    enqueue(&(*waiting),newID,newMem);
  } else if (countQueue(&(*running)) > MAX_PROG){
      printf("Cannot run over %d programs!\n", MAX_PROG);
      printf("opened program will be in the waitlist!\n");
      enqueue(&(*waiting),newID,newMem);
  } else {
    printf("The program is up and running!\n");
    enqueue(&(*running),newID,newMem);
  }
}

void printNode(node *newNode){
  printf("ID: %-5d | Memory: %d\n", newNode->id, newNode->memory);
}

void printQueue(node **top){
  if (*top == NULL) {
    printf("No program in this queue!\n");
    return;
  } else {
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode = *top;
    do{
      printNode(newNode);
      newNode = newNode->next;
    } while(newNode != NULL);
    free(newNode);
  }
}
