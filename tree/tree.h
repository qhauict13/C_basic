typedef char eType;
typedef struct node_s{
  eType *value;
  struct node_s *left,*right;
} treenode;

treenode *makeTreeNode(eType *e){
  treenode *newNode;
  newNode = (treenode*)malloc(sizeof(treenode));
  if (newNode == NULL) {
    printf("Cannot create new node!\n");
    return;
  }
  newNode->value = e;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int isLeaf(treenode *temp){
  if(temp != NULL){
    if((temp->left == NULL) && (temp->right == NULL)) return 1;
  } else {
    printf("This node is empty!\n");
    return 1;
  }
  return 0;
}

treenode *createFromSub(treenode *root,treenode *l, treenode *r){
  root->left = l;
  root->right = r;
  return root;
}

treenode *addLeftMost(treenode *root, eType *e){
  treenode *newNode = makeTreeNode(e);
  treenode *temp;
  temp = (treenode*)malloc(sizeof(treenode));
  temp = root;
  while(temp->left != NULL)
    temp = temp->left;
  temp->left = newNode;

  return newNode;
}

treenode *addRightMost(treenode *root, eType *e){
  treenode *newNode = makeTreeNode(e);
  treenode *temp;
  temp = (treenode*)malloc(sizeof(treenode));
  temp = root;
  while(temp->right != NULL)
    temp = temp->right;
  temp->right = newNode;

  return newNode;
}

void preorder(treenode *root){
  if(root != NULL){
  printf("%s ",root->value);
  preorder(root->left);
  preorder(root->right);
  }
}

void inorder(treenode *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%s ",root->value);
  inorder(root->right);
}

void postorder(treenode *root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%s ",root->value);
}

