typedef int mtype;
typedef struct node_s{
  mtype value;
  struct node_s *leftmost;
  struct node_s *rightsib;
} node;

node *root;

node *makeNode(mtype e){
  node *newNode;
  newNode = (node*)malloc(sizeof(node));
  newNode->value = e;
  newNode->leftmost = NULL;
  newNode->rightsib = NULL;
  return newNode;
}

void visit(node *p){
  if(p == NULL) printf("node empty!\n");
  else printf("%d\n", p->value);
}

node *findNode(node **top, mtype e){
  if(*top == NULL) return NULL;
  if((*top)->value == e) return *top;

  node *temp;
  temp = (*node)malloc(sizeof(node));
  temp = (*top)->leftmost;
  while(temp != NULL){
    node *newTemp = findNode(temp, e);
    if (newTemp != NULL) return newTemp;
    temp = temp->rightsib;
  }
  free(temp);
  return NULL;
}

void addChild(node **top, mtype e){
  node *newNode;
  newNode = makeNode(e);
  node *temp;
  temp = (*node)malloc(sizeof(node));
  temp = (*top)->leftmost;

  if (temp == NULL) (*top)->leftmost = newNode;
  else {
    while(temp->rightsib != NULL){
      temp = temp->rightsib;
    }
    temp->rightsib = newNode;
  }
  free(temp);
}

node *findParent(node **top, node *c){
  if ((*top) == NULL) return NULL;
  if (c == NULL) return NULL;

  node *temp;
  temp = (*node)malloc(sizeof(node));
  temp = (*top)->leftmost;

  while(temp != NULL){
    if (temp == c) return temp;
    node *cc = findParent(temp, c);
    if (cc != NULL) return cc;
    temp = temp->rightsib;
  }
  free(temp);
  return NULL;
}

int count(node **top){
  if ((*top) == NULL) return 0;
  int c = 1;
  node *temp;
  temp = (*node)malloc(sizeof(node));
  temp = (*top)->leftmost;
  while (temp != NULL){
    c += count(temp);
    temp = temp->rightsib;
  }
  free(temp);
  return c;
}

int height(node **top, node *p){
  if (p == NULL) return 0;
  int h = 0;
  node temp = temp->leftmost;
  while(temp != NULL) {
    int h1 = height(temp);
    h = h > h1? h : h1;
    temp = temp->rightsib;
  }
  return h+1;
}
int depth(node **top, node *c){
  if ((*top) == NULL) return -1;
  int d = 0;
  node *temp;
  temp = (*node)malloc(sizeof(node));
  temp = (*top)->leftmost;
  while (temp != NULL) {
    if (temp == c) return d+1;
    int d = depth(temp, c);
    temp = temp->rightsib;
  }
}

void pre_traverse(node *top){
  visit(top);
  if (top->leftmost != NULL) pre_traverse(top->leftmost);
  if (top->rightsib != NULL) pre_traverse(top->rightsib);
}

void in_traverse(node *top){
  if (top->leftmost != NULL) in_traverse(top->leftmost);
  visit(top);
  if (top->rightsib != NULL) in_traverse(top->rightsib);
}

void post_traverse(node *top){
  if (top->leftmost != NULL) post_traverse(top->leftmost);
  if (top->rightsib != NULL) post_traverse(top->rightsib);
  visit(top);
}
