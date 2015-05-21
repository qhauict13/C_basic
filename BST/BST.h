typedef struct node_b{
  void *value;
  struct node_b *left, *right;
} bnode;


//-----------make a tree node-----------------
bnode *makeTreeNode(void *e){
  bnode *newNode;
  newNode = (bnode*)malloc(sizeof(bnode));
  if(newNode == NULL) return NULL;
  newNode->value = e;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
//--------find min and max value of a tree----------
bnode *minValueNode(bnode* root){
  bnode* current = root;
  while(current->left != NULL) current = current->left;
  return current;
}
bnode *maxValueNode(bnode* root){
  bnode *current = root;
  while(current->right != NULL) current = current->right;
  return current;
}

//----------searching function-----------
bnode *search(bnode **root, void *e){
  if(e == NULL) {
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return NULL;
  }
  if((*root) == NULL) return NULL;
  int c;
  c = cmp(e,(*root)->value);
  //printf("    %d\n",c);
  if(c == 0) return (*root);
  if(c < 0) return search(&((*root)->left),e);
  if(c > 0) return search(&((*root)->right),e);
  }
//-------insert node (have value)---------------
void insertNode(bnode **root, void *e){
  int c;
  if(e == NULL) {
    fprintf(stderr,"ERROR: in %s on line %d\n",__FILE__,__LINE__);
    return;
  }
  if(*root == NULL){
    (*root) = makeTreeNode(e);
    return;
  }
    c = cmp(e,(*root)->value);
    if (c < 0) insertNode(&((*root)->left),e);
    else if (c > 0) insertNode(&((*root)->right),e);
}
//--------delete Node---------------
void deleteNode(bnode **root, void *e){
  bnode *parent, *x , *target = NULL;
  parent = x = NULL;
  if(*root == NULL) {
    printf("\nTree is empty\n");
    return;
  }
  target = search(&(*root),e);

  if(target == NULL){
    return;
  }
  if(target->left != NULL && target->right != NULL){
    parent = target;
    x = target->right;
    while(x->left != NULL){
      parent = x;
      x = x->left;
    }
    target->value = x->value;
    target = x;
  }
  if(target->left == NULL && target->right == NULL){
    if(parent->right == target) parent->right = NULL;
    else parent->left = NULL;
    free(target);
    return;
  }

  if(target->left == NULL && target->right != NULL){
    if(parent->left == target) parent->left = target->right;
    else parent->right = target->right;
    free(target);
    return;
  }

  if(target->left != NULL && target->right == NULL){
    if(parent->left == target) parent->left = target->left;
    else parent->right = target->left;
    free(target);
    return;
  }
}

//---------is a node a leaf?----------------
int isLeaf(bnode *node){
  if(node == NULL) return 0;
  else {
    if((node->left == NULL) && (node->right == NULL)) return 1;
  }
  return 0;
}
//----------create a node from 2 nodes-----------
bnode *createFromSub(bnode **root,bnode *l, bnode *r){
  (*root)->left = l;
  (*root)->right = r;
  return *root;
}

bnode *addleftMost(bnode *root, void *e){
  bnode *newNode = makeTreeNode(e);
  bnode *temp;
  temp = (bnode*)malloc(sizeof(bnode));
  temp = root;
  while(temp->left != NULL)
    temp = temp->left;
  temp->left = newNode;

  return newNode;
}

bnode *addRightMost(bnode *root, void *e){
  bnode *newNode = makeTreeNode(e);
  bnode *temp;
  temp = (bnode*)malloc(sizeof(bnode));
  temp = root;
  while(temp->right != NULL)
    temp = temp->right;
  temp->right = newNode;

  return newNode;
}
